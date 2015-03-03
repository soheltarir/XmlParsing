/**
 * @file ConfigHandler.h
 * @brief Reads Smart Order Router Configuration from SOR_Conf.xml and creates Mapping
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-06-04
 */
#ifndef _CONFIGHANDLER_H_
#define _CONFIGHANDLER_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "XmlDomDocument.h"
#include "sources.h"

#define MAX_DESTINATIONS	20

class DestConf
{
	 public:
		  void SetSource(const char* arg)	{ m_Source = GetSource(arg); }
		  enSource Source()	{ return m_Source; }
		  void SetExchange(const char* arg)	{ sprintf(m_Exchange, "%s", arg); }
		  const char* Exchange()	{return m_Exchange; };
		  void SetOpenTime(int arg)	{ m_Open_Time = arg; }
		  int OpenTime()	{ return m_Open_Time; }
		  void SetCloseTime(int arg)	{ m_Close_Time = arg; }
		  int CloseTime()	{return m_Close_Time; }
		  void SetRejs(int arg)	{ m_No_Rejs = arg; }
		  int No_Rejs()	{ return m_No_Rejs; }
		  void SetResidualTime(long arg)	{ m_Residual_Time = arg; }
		  long ResidualTime()	{ return m_Residual_Time; }
		  void SetCxlTrigger(bool arg)	{ m_Is_Cxl = arg; }
		  bool CanCxl()	{ return m_Is_Cxl; }
		  void SetSweepRatio(int arg)	{ m_SweepRatio = arg; }
		  int SweepRatio()	{ return m_SweepRatio; }
	 private:
		  enSource m_Source;
		  char m_Exchange[32];
		  int m_Open_Time;		//format is HHMM
		  int m_Close_Time;
		  int m_No_Rejs;
		  long m_Residual_Time;
		  int m_SweepRatio;
		  bool m_Is_Cxl;			//If Cancel trigger then true, if Replace trigger the false
};
			
class ConfigHandler
{
	 public:
		  ConfigHandler(const char* xmlFile)
		  {
				string value;
				XmlDomDocument* doc = new XmlDomDocument(xmlFile);
				if (doc)
				{
					 m_TotalDests = doc->getChildCount("FLEXTRADE", 0, "SOR");
					 for (int i = 0; i < doc->getChildCount("FLEXTRADE", 0, "COMMON"); i++)
						  value = doc->getAttributeValue("COMMON", i, "DEBUG_LEVEL");
					 m_DebugLvl = atoi(value.c_str());

					 for (int i = 0; i < m_TotalDests; i++)
					 {
						  DestConf* _TmpDest;
						  cout << "1 ";
						  value = doc->getAttributeValue("SOR", i, "DESTINATION");
						  cout << "2 ";
						  _TmpDest->SetExchange(value.c_str());
						  value = doc->getAttributeValue("SOR", i, "SOURCE");
						  cout << "3 ";
						  _TmpDest->SetSource(value.c_str());
						  value = doc->getChildValue("SOR", i, "OPEN_TIME");
						  _TmpDest->SetOpenTime(atoi(value.c_str()));
						  value = doc->getChildValue("SOR", i, "CLOSE_TIME");
						  _TmpDest->SetCloseTime(atoi(value.c_str()));
						  value = doc->getChildValue("SOR", i, "SWEEP_RATIO");
						  _TmpDest->SetSweepRatio(atoi(value.c_str()));
						  value = doc->getChildValue("SOR", i, "STALE_AFT_REJS");
						  _TmpDest->SetRejs(atoi(value.c_str()));
						  value = doc->getChildValue("SOR", i, "RESIDUAL_TIME");
						  _TmpDest->SetResidualTime(atoi(value.c_str()));
						  value = doc->getChildValue("SOR", i, "CXL_OR_RPL");
						  if (value == "CXL")
								_TmpDest->SetCxlTrigger(true);
						  else if (value == "RPL")
								_TmpDest->SetCxlTrigger(false);
						  else
						  {
								sprintf(m_strError, "FATAL ERROR: Invalid value %s for field CXL_OR_RPL", value.c_str());
								return;
						  }
						  map <string, DestConf*>::iterator it;
						  it = MapDests.find(_TmpDest->Exchange());
						  if (it == MapDests.end())
						  {
								MapDests[_TmpDest->Exchange()] = _TmpDest;
								m_vectDests.push_back(_TmpDest->Exchange());
						  }
						  else
						  {
								sprintf(m_strError, "ERROR: Exchange %s already exists in destination mapping", _TmpDest->Exchange());
								return;
						  }
						  delete _TmpDest;
					 }
				}
				delete doc;
		  }
		  char* GetError()	{ return m_strError; }
		  int TotalDest()		{ return m_TotalDests; }
		  enSource Source(const char* _exch)
		  {
				enSource def = (enSource)0;
				if (MapDests.find(_exch) == MapDests.end())
					 return def;
				else
					 return (MapDests[_exch]->Source());
		  }
		  int OpenTime(const char* _exch)
		  {
				if (MapDests.find(_exch) == MapDests.end())
					 return -1;
				else
					 return (MapDests[_exch]->OpenTime());
		  }
		  int CloseTime(const char* _exch)
		  {
				if (MapDests.find(_exch) == MapDests.end())
					 return -1;
				else
					 return (MapDests[_exch]->CloseTime());
		  }
		  int SweepRatio(const char* _exch)
		  {
				if (MapDests.find(_exch) == MapDests.end())
					 return -1;
				else
					 return (MapDests[_exch]->SweepRatio());
		  }
		  int Rejs(const char* _exch)
		  {
				if (MapDests.find(_exch) == MapDests.end())
					 return -1;
				else
					 return (MapDests[_exch]->No_Rejs());
		  }
		  long ResidualTime(const char* _exch)
		  {
				if (MapDests.find(_exch) == MapDests.end())
					 return -1;
				else
					 return (MapDests[_exch]->ResidualTime());
		  }
		  /**
			* @brief Gives Exchanges listed in SOR_Config.xml
			*
			* @param i Sequence of exchange as listed in SOR_Config.xml
			*
			* @return exchange name
			*/
		  string Exchange(int i)
		  {
				if (i > m_vectDests.size())
					 return "";
				else
					 return m_vectDests.at(i);
		  }


	 private:
		  int m_TotalDests;
		  int m_DebugLvl;
		  char* m_strError;
		  bool m_DoContinue;
		  map <string, DestConf*> MapDests;
		  vector <string> m_vectDests;
};

#endif
