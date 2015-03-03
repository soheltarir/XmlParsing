/**
 * @file sources.h
 * @brief Lists all valid marketdepth sources for the OM
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-06-04
 */
#ifndef _SOURCES_H_
#define _SOURCES_H_

#include <stdio.h>

using namespace std;

#define Source_Tbl \
			Declare(DEFAULT,"")                             /*for use within rules only*/           \
         Declare(ML,     "ML")                   /*Merril Lynch*/                \
         Declare(NSDQ,   "NSDQ")                 /*NASDAQ exchange*/             \
         Declare(REDI,   "REDI")                 /*redibook*/            \
         Declare(PINK,   "PINK")                 /*instinet*/            \
         Declare(BLOOM,  "BLO")                  /*bloomberg*/           \
         Declare(MST,	 "MS")                   /*morgan stanley*/              \
         Declare(GL,     "GLT")                  /*GL trade*/            \
         Declare(BOFA,   "BOFA")                 /*Banc of America*/             \
         Declare(REGBKAG,"REGBKAG")              /*Reg Book Aggregated*/         \
         Declare(ARCA,   "ARCA")                 /*archipelago data*/            \
         Declare(OTCBB,  "OTCBB")                /*BBDS Feed*/           \
         Declare(REUT,   "REUT")                 /*reuters*/             \
         Declare(SNPC,   "SNPC")                 /*comstock*/            \
         Declare(ATFI,   "ATFI")                 /*AT financial*/                \
         Declare(SGX,    "SGX")                  /*Singapore Exchange*/          \
         Declare(BLEND,  "BLEND")                /*blended book - used internally by Flextrade*/         \
         Declare(OPBK,   "OPBK")                 /*NYSE openbook*/               \
         Declare(TRNT,   "TRNT")                 /*Toronto stock exchange*/              \
         Declare(CME,    "CME")                  /*Chicago Mercantile Exchange*/         \
         Declare(CDNX,   "CDNX")                 /*Canadian Futures Exchange*/           \
         Declare(BTRD,   "BTRD")                 /*Bloomberg BTrade FX*/\
         Declare(FLEX,   "FLEX")                 /*Internal - for Flextrade orders*/             \
         Declare(HSFX,   "HSFX")                 /*Hotspot FX*/          \
         Declare(REGBK,  "REGBK")                /*Regional Top-Of-Book Level 1.5*/              \
         Declare(FTFIX,  "FIX")                  /*FIX engine*/          \
         Declare(NQDS,   "NQDS")                 /*Nasdaq NQDS feed*/            \
         Declare(DRES,   "DRES")                 /*Dresdner*/            \
         Declare(IOI,    "IOI")                  /*Internal - for Flextrade Iois*/               \
         Declare(SEAQ,   "SEAQ")                 /*London SETS auto quotation*/          \
         Declare(SETS,   "SETS")                 /*London SETS*/         \
         Declare(NYLQ,   "NYLQ")                 /*New York Liquidity Quote*/            \
         Declare(RBOS,   "RBOS")                 /*Royal Bank of Scotland*/              \
         Declare(UBS,    "UBS")                  /*UBS*/         \
         Declare(CITI,   "CITI")                 /*Citibank*/            \
         Declare(CSFB,   "CSFB")                 /*Credit Suisse First Boston*/          \
         Declare(DBFX,   "DBFX")                 /*Deutsche Bank FX*/            \
         Declare(BARC,   "BARC")                 /*Barclays*/            \
         Declare(EBS,    "EBS")                  /*EBS*/         \
         Declare(HSBC,   "HSBC")                 /*Hongkong and Shanghai Bank*/          \
         Declare(OSE,    "OSE")                  /*Osaka Stock Exchange */               \
         Declare(JPMC,   "JPMC")                 /*JP Morgan Chase*/             \
         Declare(CRNX,   "CRNX")                 /*Currenex*/            \
         Declare(SAXO,   "SAXO")                 /*Saxo bank*/           \
         Declare(GSFX,   "GSFX")                 /*Goldman Sachs FX*/            \
         Declare(LAVA,   "LAVA")                 /*Lava Trading*/                \
         Declare(OPRA,   "OPRA")                 /*Options Price Reporting Authority*/           \
         Declare(FIMAT,  "FIMAT")                /*FIMAT - Currenex white label*/                \
         Declare(FLEXOT, "FLEXOT")               /*For Flex internal purposes, used for Level-2*/                \
         Declare(AMEX,   "AMEX")                 /*American Exchange for option prices*/         \
         Declare(BOX,    "BOX")                  /*for option prices*/           \
         Declare(CBOE,   "CBOE")                 /*Chicago Board of Exchange for option prices*/         \
         Declare(ARCA_OP,"ARCA_OP")              /*ARCA Options Exchange*/               \
         Declare(PHLX,   "PHLX")                 /*Philadelphia Stock Exchange*/         \
         Declare(ISE,    "ISE")                  /*International Stock Exchange*/                \
         Declare(FXCM,   "FXCM")                 /*FXCM - Currenex whitelabel*/          \
         Declare(CBOT,   "CBOT")                 /*Chicago Board of Trade*/              \
         Declare(EUREX,  "EUREX")                /*Eurex*/               \
         Declare(AIG,    "AIG")                  /*American Insurance Group*/            \
         Declare(ABN,    "ABN")                  /*ABN Amro*/            \
         Declare(OPRA_CONSOL,"MULT")                 /*Consolidate Opra*/            \
         Declare(SEB,    "SEB")                  /*SEB Bank (Skandinaviska Enskilda Banken)*/            \
         Declare(ADM,    "ADM")                  /*ADM - Currenex whitelabel*/           \
         Declare(LCAP,   "LCAP")                 /*London Capital - Currenex whitelabel*/                \
         Declare(FCST,   "FCST")                 /*FCStone - Currenex whitelabel*/               \
         Declare(GFT,    "GFT")                  /*Global Forex Trading - Currenex whitelabel*/          \
         Declare(MAN,    "MAN")                  /*Man FX - Currenex whitelabel*/                \
         Declare(MAREX,  "MAREX")                /*Marex Financial - Currenex whitelabel*/               \
         Declare(ODL,    "ODL")                  /*ODL Securities - Currenex whitelabel*/                \
         Declare(PFG,    "PFG")                  /*Peregrine Financial - Currenex whitelabel*/           \
         Declare(FXMS,   "FXMS")                 /*Reuters-CME FXMarketSpace*/           \
         Declare(TBF,    "TBF")                  /*Toronto broadcast feed (TSX)*/                \
         Declare(CBF,    "CBF")                  /*TSXV broadcast feed*/         \
         Declare(PBF,    "PBF")                  /*Pure broadcast feed*/         \
         Declare(WEST,   "WEST")                 /*Westpac*/             \
         Declare(CME_IMPL,"CME_IMPL")             /*CME Implied Order Book*/              \
         Declare(FXALL,   "FXALL")                /* FXAll (a.k.a. Accelor)*/             \
         Declare(DUMY,    "DUMY")                 /* DUMMY entry to prevent GCFX to show up as yellow*/           \
         Declare(GCFX,    "GCFX")                 /* Gain Capital*/               \
         Declare(SCFX,    "SCFX")                 /* Standard Charted Bank*/              \
         Declare(SOGC,    "SOGC")                 /* Soc Gen*/            \
         Declare(UBSB,    "UBSB")                 /* UBS "B" Feed*/               \
         Declare(UBSC,    "UBSC")                 /* UBS "C" Feed*/               \
         Declare(CITII,   "CITII")                /* CITI Industrial feed*/               \
         Declare(CITIP,   "CITIP")                /* CITI Preferred feed*/                \
         Declare(MCX,     "MCX")                  /* Multi Commodity Exchange of India*/          \
         Declare(SENSEX,  "SENSEX")               /* Bombay Stock Exchange*/              \
         Declare(GSFXI,   "GSFXI")                /* Goldman Sachs Industrial feed*/              \
         Declare(GSFXP,   "GSFXP")                /* Goldman Sachs Preferred feed*/               \
         Declare(CHIX,    "CHIX")                 /* Chi-X ATS*/          \
         Declare(BREN,    "BREN")                 /* Brussels Euronext*/          \
         Declare(PAEN,    "PAEN")                 /* Paris Euronext*/             \
         Declare(LSEN,    "LSEN")                 /* Lisbon Euronext*/            \
         Declare(AMEN,    "AMEN")                 /* Amsterdam Euronext*/         \
         Declare(BATS,    "BATS")                 /* Boston ATS*/         \
         Declare(EDGX,    "EDGX")                 /* Direct edge*/                \
         Declare(OMEGA,   "OMEGA")                /* Canadian*/           \
         Declare(SCFXP,   "SCFXP")                /* Standard Chartared Bank Prices*/             \
         Declare(ALPHA,   "ALPHA")                /* Alpha trading system in Canada*/             \
         Declare(FTRD,    "FTRD")                 /* US Equity Regional book aggregated by price*/                        \
         Declare(HSBC2,   "HSBC2")                /* Stream 2 from HSBC */                \
         Declare(HSBC3,   "HSBC3")                /* Stream 3 from HSBC */                \
         Declare(BOFA2,   "BOFA2")                /* Stream 2 from BofA */                \
         Declare(BOFA3,   "BOFA3")                /* Stream 3 from BofA */                \
         Declare(NATXS,   "NATXS")                /* Natixis */           \
         Declare(BMF,     "BMF")                  /* BM&F Brazilian */    \
         Declare(BMFAGG,  "BMFAGG")               /* Brazilian B & MF - Price Agg Book */         \
         Declare(BSE,     "BSE")                  /* Brazilian Stock Ex */                \
         Declare(BSEAGG,  "BSEAGG")               /* Brazilian Stock Ex - Price Agg Book */               \
         Declare(EDGEFX,  "EDGEFX")               /* Newedge FX */                \
         Declare(GFX,     "GFX")          /* GFX */                \
         Declare(FLXSTRT, "FLXSTRT")              /* Flex internal for strategy orders display in L2 */ \
         Declare(NSDQ_OP, "NSDQ_OP")              /* NASDAQ identifier for Options*/ \
      	Declare(NOMU,    "NOMU")         /* NOMU */                \
      	Declare(NSE,     "NSE")          /* NSE - National Stock Exchange of India */  \
         Declare(MS2,     "MS2")                  /* Morgan Stanley - Second stream */ \
         Declare(LUCID,   "LUCID")                /* Lucid Markets - Primary stream */ \
         Declare(LUCID2,  "LUCID2")               /* Licid Markets - Second stream */ \
         Declare(BNPFX,   "BNPFX")                /* BNP FX stream */ \
         Declare(ASX,     "ASX")                  /* Australian Securities Exchange*/ \
         Declare(HKEX,    "HKEX")                 /* Hong Kong Exchange */ \
         Declare(TSE,     "TSE")                  /* Tokyo Stock Exchange */ \
         Declare(NZX,     "NZX")                  /* New Zealand Stock Exchange */ \
         Declare(MX,      "MX")                   /* Montreal Exchange */ \
         Declare(MXIMPL,  "MXIMPL")        /* Montreal Exchange Implied Order */\
         Declare(QUOTE,   "QUOTE")                /* Quote */\
         Declare(SET,     "SET")                  /* Stock Exchange of Thailand */\
         Declare(BM,      "BM")                   /* Bursa Malaysia */\
     		Declare(RBC,     "RBC")          /* Royal Bank of Canada */\
         Declare(SSFX,    "SSFX")        /* State Street */\
         Declare(CIBC,    "CIBC")        /* Canadian Imperial Bank of Commerce */\
         Declare(RCG,     "RCG")         /* Rosenthal Collins Group */\
         Declare(INTFX,   "INTFX")     /* Integral FX */\
         Declare(FXDD,    "FXDD")     /* FX Direct Dealer */\
         Declare(ILQ,     "ILQ")          /* Institutional Liquidity */\
         Declare(VFX,     "VFX")         /* Virtu Financial */\
         Declare(HCFX,    "HCFX")      /* Henning and Carrey */\
         Declare(ADSS,    "ADSS")      /* ADS Securities */\
         Declare(XFIN,    "XFIN")       /* XenFin */\
         Declare(BTP,     "BTP")          /* BT Prime */\
			Declare(GSA,     "GSA")        /* GSA Capital  */\
			Declare(COMZ,    "COMZ")   /* Commerz Bank  */\


#define Declare(a,b) a,
enum enSource {
	Source_Tbl
	MAX_SOURCE								/*Maximum number of Sources*/
};
#undef Declare

#define Declare(a,b) b,
char *source_name[] = {
	Source_Tbl
};
#undef Declare

enSource GetSource(const char* arg)
{
		enSource ret;
	 	for (int i = 0; i < MAX_SOURCE; i++)
		{
			 if (!strcmp(source_name[i], arg))	{ ret = (enSource)i; return ret; }
		}

		ret = (enSource)0;
		return ret;
}
#endif
