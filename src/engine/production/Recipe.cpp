/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/production/Recipe.cpp/Recipe.cpp.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 19 déc. 2019: File creation (niels)
 */

#include <Recipe.h>

Recipe::Recipe(s_RecipeUID _recipeID)
: m_RecipeID(_recipeID)
, m_ProcessList(nullptr)
{
	m_ProcessList = new ObjList<ProcessStep>();
}

Recipe::~Recipe()
{
	delete m_ProcessList;
}

s_RecipeUID Recipe::getRecipeID()
{
	return m_RecipeID;
}

void Recipe::addProcessStep(ProcessStep _processStep)
{
	m_ProcessList->addObject(_processStep);
}

ObjList<ProcessStep> *Recipe::getListOfProcesses()
{
	return m_ProcessList;
}

RecipeFollower::RecipeFollower(Recipe *_recipe)
: m_Recipe(nullptr)
, m_CurrentStep(nullptr)
, m_CurrentRawMaterial(nullptr)
{
	// TODO assert _recipe is not null
	m_Recipe = _recipe;
	m_CurrentStep = new ObjListIterator<ProcessStep>(_recipe->getListOfProcesses());
	m_CurrentRawMaterial = new ObjListIterator<ProcessStep>(m_CurrentStep->getCurrent()->getRawMaterialsList());
}

RecipeFollower::~RecipeFollower()
{
	delete m_CurrentStep;
	delete m_CurrentRawMaterial;
}

ProcessStep *RecipeFollower::getNextStep()
{
	ProcessStep * l_ret = nullptr;

	// TODO assert m_CurrentStep is not null
	l_ret = m_CurrentStep->iterate();

	return l_ret;
}

ProcessStep *RecipeFollower::getCurrentStep()
{
	ProcessStep * l_ret = nullptr;

	// TODO assert m_CurrentStep is not null
	l_ret = m_CurrentStep->getCurrent();

	return l_ret;
}

s_ItemTypeUUID getNextRawMaterial()
{
	s_ItemTypeUUID l_ret = *(m_CurrentRawMaterial->iterate());

	return l_ret;
}

s_ItemTypeUUID getCurrentRawMaterial()
{
	s_ItemTypeUUID l_ret = *(m_CurrentRawMaterial->getCurrent());

	return l_ret;
}
