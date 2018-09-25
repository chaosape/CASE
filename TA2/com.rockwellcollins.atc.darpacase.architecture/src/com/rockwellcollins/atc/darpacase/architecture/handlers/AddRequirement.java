package com.rockwellcollins.atc.darpacase.architecture.handlers;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.emf.common.util.EList;
import org.eclipse.jface.window.Window;
import org.eclipse.ui.PlatformUI;
import org.eclipse.xtext.resource.XtextResource;
import org.eclipse.xtext.ui.editor.XtextEditor;
import org.eclipse.xtext.ui.editor.utils.EditorUtils;
import org.eclipse.xtext.util.concurrent.IUnitOfWork;
import org.osate.aadl2.AnnexSubclause;
import org.osate.aadl2.Classifier;
import org.osate.aadl2.NamedElement;
import org.osate.aadl2.ThreadType;
import org.osate.aadl2.impl.AadlPackageImpl;
import org.osate.aadl2.impl.DefaultAnnexSubclauseImpl;
import org.osate.aadl2.impl.PackageSectionImpl;

import com.rockwellcollins.atc.darpacase.architecture.CaseClaimsManager;
import com.rockwellcollins.atc.darpacase.architecture.dialogs.ImportRequirementsDialog;

public class AddRequirement extends AbstractHandler {

	@Override
	public Object execute(ExecutionEvent event) throws ExecutionException {

//		final String componentName = "FlightPlanner";
//		final String reqName = "well_formed";
//		final String reqText = "The Flight Planner shall receive a well-formed command from the Ground Station";

		// TODO: These should all be in a single class
		List<String> reqNames = null;
		List<String> reqTexts = null;
		List<String> reqComps = null;

		// Open wizard to enter filter info
		ImportRequirementsDialog wizard = new ImportRequirementsDialog(
				PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
		wizard.create();
		if (wizard.open() == Window.OK) {
			reqNames = wizard.getReqNames();
			reqTexts = wizard.getReqTexts();
			reqComps = wizard.getComponents();
		}

		for (int i = 0; i < reqNames.size(); i++) {
			// Insert requirements into model
			addRequirement(reqComps.get(i), reqNames.get(i), reqTexts.get(i));
			// Add corresponding resolute clauses to *_CASE_Claims.aadl
			addClaims(reqNames.get(i), reqTexts.get(i));
		}

		return null;
	}

	private void addRequirement(String componentName, String reqName, String reqText) {
		// Get the active xtext editor so we can make modifications
		final XtextEditor xtextEditor = EditorUtils.getActiveXtextEditor();

		xtextEditor.getDocument().modify(new IUnitOfWork.Void<XtextResource>() {

			@Override
			public void process(final XtextResource resource) throws Exception {
				// Get the component in the model
				final AadlPackageImpl aadlPkg = (AadlPackageImpl) resource.getContents().get(0);
				PackageSectionImpl pkgSection = (PackageSectionImpl) aadlPkg.getOwnedPublicSection();
				int idx = getIndex(componentName, pkgSection.getOwnedClassifiers());
				Classifier classifier = pkgSection.getOwnedClassifiers().get(idx);

				ThreadType threadType = (ThreadType) classifier;
				EList<AnnexSubclause> annexSubclauses = threadType.getOwnedAnnexSubclauses();
				String assumeStatement = "{**" + System.lineSeparator() + "\t\t\tassume \"" + reqText + "\" : FALSE;";
				String proveStatement = "{**" + System.lineSeparator() + "\t\t\tprove (" + reqName + "())";

				Iterator<AnnexSubclause> annexSubclause = annexSubclauses.iterator();
				while (annexSubclause.hasNext()) {
					DefaultAnnexSubclauseImpl annexSubclauseImpl = (DefaultAnnexSubclauseImpl) annexSubclause.next();
					String sourceText = annexSubclauseImpl.getSourceText();

					if (annexSubclauseImpl.getName().equalsIgnoreCase("agree")) {
						// Add AGREE assume statement
						assumeStatement = sourceText.replace("{**", assumeStatement);
						// Delete annex subclause from owned subclauses. Will add it back later.
						// There must be a better way to get the formatting to display correctly.
						annexSubclause.remove();
					} else if (annexSubclauseImpl.getName().equalsIgnoreCase("resolute")) {
						// Add Resolute prove statement
						proveStatement = sourceText.replace("{**", proveStatement);
						// Delete annex subclause from owned subclauses. Will add it back later.
						// There must be a better way to get the formatting to display correctly.
						annexSubclause.remove();
					}
				}

				DefaultAnnexSubclauseImpl agreeSubclause = (DefaultAnnexSubclauseImpl) threadType
						.createOwnedAnnexSubclause();
				agreeSubclause.setName("agree");
				if (!assumeStatement.contains("**}")) {
					assumeStatement = assumeStatement + System.lineSeparator() + "\t\t**}";
				}
				agreeSubclause.setSourceText(assumeStatement);

				DefaultAnnexSubclauseImpl resoluteSubclause = (DefaultAnnexSubclauseImpl) threadType
						.createOwnedAnnexSubclause();
				resoluteSubclause.setName("resolute");
				if (!proveStatement.contains("**}")) {
					proveStatement = proveStatement + System.lineSeparator() + "\t\t**}";
				}
				resoluteSubclause.setSourceText(proveStatement);


				// Delete and re-insert this component from package section
				// This seems to be the only way to get the formatting (mostly) correct
				pkgSection.getOwnedClassifiers().remove(idx);
				pkgSection.getOwnedClassifiers().add(idx, classifier);
			}
		});
	}

	private void addClaims(String reqName, String reqText) {

		// TODO: Get *_CASE_Claims.aadl resource in working directory
		// TODO: If it doesn't exist, create it

		// Add requirement
		CaseClaimsManager.getInstance().addFunctionDefinition(reqName, reqText);
	}

	/**
	 * Returns the index of a component with the specified name in the specified element list.
	 * @param compName - Component name
	 * @param elements - Collection of elements
	 * @return An identifier that is unique in the specified list
	 */
	private int getIndex(String compName, final Collection<? extends NamedElement> elements) {
		int idx = 0;

		for (NamedElement e : elements) {
			if (e.getName().equals(compName)) {
				break;
			} else {
				idx++;
			}
		}
		return idx;
	}

}
