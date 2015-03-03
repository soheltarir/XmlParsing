/**
 * @file XmlDomDocument.h
 * @brief Parser for XML Document
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-06-03
 */
#ifndef _XMLDOMDOCUMENT_H_
#define _XMLDOMDOCUMENT_H_

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <string>

using namespace std;
using namespace xercesc;

class XmlDomDocument
{
	 DOMDocument* m_doc;
	 public:
	 	XmlDomDocument(const char* xmlfile);
		~XmlDomDocument();
		string getChildValue(const char* parentTag, int parentIndex, const char* childTag);
		string getAttributeValue(const char* elementTag, int elementIndex, const char* attributeTag);
		int getChildCount(const char* parentTag, int parentIndex, const char* childTag);
	
	 private:
		//XmlDomDocument();
		//XmlDomDocument(const XmlDOMDocument&);
};

class XmlDomErrorHandler : public HandlerBase
{
	 public:
		  void fatalError(const SAXParseException &exc)
		  {
				printf("Fatal parsing error at line %d\n", (int)exc.getLineNumber());
				exit(-1);
		  }

};

void createParser();

#endif
