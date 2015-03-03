/**
 * @file XmlDomDocument.cpp
 * @brief Parser for XML Document
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-06-03
 */
#include "XmlDomDocument.h"

XercesDOMParser* parser = NULL;
ErrorHandler* errorHandler = NULL;

void createParser()
{
	 if (!parser)
	 {
		  XMLPlatformUtils::Initialize();
		  parser = new XercesDOMParser();
		  errorHandler = (ErrorHandler*) new XmlDomErrorHandler();
		  parser->setErrorHandler(errorHandler);
	 }
}

XmlDomDocument::XmlDomDocument(const char* xmlfile) : m_doc(NULL)
{
	 createParser();
	 parser->parse(xmlfile);
	 m_doc = parser->getDocument();	 
	//m_doc = reinterpret_cast<DOMDocument*>(parser);
}

XmlDomDocument::~XmlDomDocument()
{
	 if (m_doc)	m_doc->release();
}

string XmlDomDocument::getChildValue(const char* parentTag, int parentIndex, const char* childTag)
{
	 XMLCh* temp = XMLString::transcode(parentTag);
	 DOMNodeList* list = m_doc->getElementsByTagName(temp);
	 XMLString::release(&temp);

	 DOMElement* parent = reinterpret_cast<DOMElement*>(list->item(parentIndex));
	 DOMElement* child = dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(0));

	 string value;
	 if (child) 
	 {
		  char* temp2 = XMLString::transcode(child->getTextContent());
		  value = temp2;
		  XMLString::release(&temp2);
	 }
	 else
	 {
		  value = "";
	 }
	 return value;
}

string XmlDomDocument::getAttributeValue (const char* elementTag, int elementIndex, const char* attributeTag)
{
	 XMLCh* temp = XMLString::transcode(elementTag);
	 DOMNodeList* list = m_doc->getElementsByTagName(temp);
	 XMLString::release(&temp);

	 DOMElement* element = dynamic_cast<DOMElement*>(list->item(elementIndex));
	 temp = XMLString::transcode(attributeTag);
	 char* temp2 = XMLString::transcode(element->getAttribute(temp));

	 string value = temp2;
	 XMLString::release(&temp);
	 XMLString::release(&temp2);
	 return value;
}

int XmlDomDocument::getChildCount(const char* parentTag, int parentIndex, const char* childTag)
{
	 XMLCh* temp = XMLString::transcode(parentTag);
	 DOMNodeList* list = m_doc->getElementsByTagName(temp);
	 XMLString::release(&temp);

	 DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
	 DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));
	 return (int)childList->getLength();
}
