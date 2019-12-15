#include <INode.h>

INode::INode()
: IGraphElement()
, m_CarriedToken(nullptr)
, m_Input(nullptr)
, m_Outputs(nullptr)
{
	m_Outputs = new ObjList<IGraphElement>();
}

INode::~INode()
{
	delete m_Outputs;
}

void INode::setToken(IToken *_token)
{
	m_CarriedToken = _token;
}

IToken *INode::getToken()
{
	return m_CarriedToken;
}

void INode::setInput(IGraphElement *_input)
{
	m_Input = _input;
}

IGraphElement *INode::getInput()
{
	return m_Input;
}

void INode::addOutput(IGraphElement *_output)
{
	m_Outputs->addObject(_output);
}

ObjList<IGraphElement> *INode::getOutputs()
{
	return m_Outputs;
}
