#include <stdio.h>
#include "MA_EE.h"
#include "MIPS.h"

using namespace MIPSReflection;

void CMA_EE::ReflOpRdRt(INSTRUCTION* pInstr, CMIPS* pCtx, uint32 nAddress, uint32 nOpcode, char* sText, unsigned int nCount)
{
	uint8 nRT, nRD;

	nRT = (uint8)((nOpcode >> 16) & 0x001F);
	nRD = (uint8)((nOpcode >> 11) & 0x001F);

	sprintf(sText, "%s, %s", CMIPS::m_sGPRName[nRD], CMIPS::m_sGPRName[nRT]);
}

void CMA_EE::ReflOpRsImm(INSTRUCTION* pInstr, CMIPS* pCtx, uint32 nAddress, uint32 nOpcode, char* sText, unsigned int nCount)
{
	uint8 nRS;
	uint16 nImm;

	nRS  = (uint8) ((nOpcode >> 21) & 0x001F);
	nImm = (uint16)((nOpcode >>  0) & 0xFFFF);

	sprintf(sText, "%s, $%0.4X", CMIPS::m_sGPRName[nRS], nImm);
}

INSTRUCTION CMA_EE::m_cReflMmi[64] =
{
	//0x00
	{	"MADD",		NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PLZCW",	NULL,			CopyMnemonic,		ReflOpRdRs,			NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x08
	{	"MMI0",		NULL,			SubTableMnemonic,	SubTableOperands,	SubTableIsBranch,	SubTableEffAddr	},
	{	"MMI2",		NULL,			SubTableMnemonic,	SubTableOperands,	SubTableIsBranch,	SubTableEffAddr	},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x10
	{	"MFHI1",	NULL,			CopyMnemonic,		ReflOpRd,			NULL,				NULL			},
	{	"MTHI1",	NULL,			CopyMnemonic,		ReflOpRs,			NULL,				NULL			},
	{	"MFLO1",	NULL,			CopyMnemonic,		ReflOpRd,			NULL,				NULL			},
	{	"MTLO1",	NULL,			CopyMnemonic,		ReflOpRs,			NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x18
	{	"MULT1",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"MULTU1",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"DIV1",		NULL,			CopyMnemonic,		ReflOpRsRt,			NULL,				NULL			},
	{	"DIVU1",	NULL,			CopyMnemonic,		ReflOpRsRt,			NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x20
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x28
	{	"MMI1",		NULL,			SubTableMnemonic,	SubTableOperands,	SubTableIsBranch,	SubTableEffAddr	},
	{	"MMI3",		NULL,			SubTableMnemonic,	SubTableOperands,	SubTableIsBranch,	SubTableEffAddr	},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x30
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PSLLH",	NULL,			CopyMnemonic,		ReflOpRdRtSa,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PSRLH",	NULL,			CopyMnemonic,		ReflOpRdRtSa,		NULL,				NULL			},
	{	"PSRAH",	NULL,			CopyMnemonic,		ReflOpRdRtSa,		NULL,				NULL			},
	//0x38
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
};

INSTRUCTION CMA_EE::m_cReflMmi0[32] =
{
	//0x00
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PSUBW",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PADDH",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PCGTH",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"PMAXH",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	//0x08
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PSUBB",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x10
	{	"PADDSW",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PEXTLW",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PEXTLH",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"PPACH",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	//0x18
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PEXTLB",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"PPACB",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PEXT5",	NULL,			CopyMnemonic,		ReflOpRdRt,			NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
};

INSTRUCTION CMA_EE::m_cReflMmi1[32] =
{
	//0x00
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PCEQW",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PMINH",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	//0x08
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x10
	{	"PADDUW",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PEXTUW",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x18
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PEXTUB",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"QFSRV",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
};

INSTRUCTION CMA_EE::m_cReflMmi2[32] =
{
	//0x00
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x08
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PCPYLD",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x10
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PAND",		NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"PXOR",		NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x18
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
};

INSTRUCTION CMA_EE::m_cReflMmi3[32] =
{
	//0x00
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x08
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PCPYUD",	NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x10
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"POR",		NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	"PNOR",		NULL,			CopyMnemonic,		ReflOpRdRsRt,		NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	//0x18
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	"PCPYH",	NULL,			CopyMnemonic,		ReflOpRdRt,			NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
	{	NULL,		NULL,			NULL,				NULL,				NULL,				NULL			},
};

void CMA_EE::SetupReflectionTables()
{
	memcpy(m_ReflMmi, m_cReflMmi, sizeof(INSTRUCTION) * 64);
	memcpy(m_ReflMmi0, m_cReflMmi0, sizeof(INSTRUCTION) * 32);
	memcpy(m_ReflMmi1, m_cReflMmi1, sizeof(INSTRUCTION) * 32);
	memcpy(m_ReflMmi2, m_cReflMmi2, sizeof(INSTRUCTION) * 32);
	memcpy(m_ReflMmi3, m_cReflMmi3, sizeof(INSTRUCTION) * 32);

	m_ReflMmiTable.pTable						= m_ReflMmi;
	m_ReflMmiTable.nShift						= 0;
	m_ReflMmiTable.nMask						= 0x3F;

	m_ReflMmi0Table.pTable						= m_ReflMmi0;
	m_ReflMmi0Table.nShift						= 6;
	m_ReflMmi0Table.nMask						= 0x1F;

	m_ReflMmi1Table.pTable						= m_ReflMmi1;
	m_ReflMmi1Table.nShift						= 6;
	m_ReflMmi1Table.nMask						= 0x1F;

	m_ReflMmi2Table.pTable						= m_ReflMmi2;
	m_ReflMmi2Table.nShift						= 6;
	m_ReflMmi2Table.nMask						= 0x1F;

	m_ReflMmi3Table.pTable						= m_ReflMmi3;
	m_ReflMmi3Table.nShift						= 6;
	m_ReflMmi3Table.nMask						= 0x1F;

	//Fix MIPSIV tables
	m_ReflGeneral[0x1C].sMnemonic				= "MMI";
	m_ReflGeneral[0x1C].pSubTable				= &m_ReflMmiTable;
	m_ReflGeneral[0x1C].pGetMnemonic			= SubTableMnemonic;
	m_ReflGeneral[0x1C].pGetOperands			= SubTableOperands;
	m_ReflGeneral[0x1C].pIsBranch				= SubTableIsBranch;
	m_ReflGeneral[0x1C].pGetEffectiveAddress	= SubTableEffAddr;

	m_ReflGeneral[0x1E].sMnemonic				= "LQ";
	m_ReflGeneral[0x1E].pGetMnemonic			= MIPSReflection::CopyMnemonic;
	m_ReflGeneral[0x1E].pGetOperands			= ReflOpRtOffRs;

	m_ReflGeneral[0x1F].sMnemonic				= "SQ";
	m_ReflGeneral[0x1F].pGetMnemonic			= MIPSReflection::CopyMnemonic;
	m_ReflGeneral[0x1F].pGetOperands			= ReflOpRtOffRs;

	m_ReflSpecial[0x1D].sMnemonic				= "REEXCPT";
	m_ReflSpecial[0x1D].pGetMnemonic			= MIPSReflection::CopyMnemonic;
	m_ReflSpecial[0x1D].pGetOperands			= NULL;

	m_ReflRegImm[0x18].sMnemonic				= "MTSAB";
	m_ReflRegImm[0x18].pGetMnemonic				= MIPSReflection::CopyMnemonic;
	m_ReflRegImm[0x18].pGetOperands				= ReflOpRsImm;

	m_ReflRegImm[0x19].sMnemonic				= "MTSAH";
	m_ReflRegImm[0x19].pGetMnemonic				= MIPSReflection::CopyMnemonic;
	m_ReflRegImm[0x19].pGetOperands				= ReflOpRsImm;

	//Fix MULT/MULTU operands
	m_ReflSpecial[0x18].pGetOperands			= ReflOpRdRsRt;
	m_ReflSpecial[0x19].pGetOperands			= ReflOpRdRsRt;

	m_ReflMmi[0x08].pSubTable					= &m_ReflMmi0Table;
	m_ReflMmi[0x09].pSubTable					= &m_ReflMmi2Table;
	m_ReflMmi[0x28].pSubTable					= &m_ReflMmi1Table;
	m_ReflMmi[0x29].pSubTable					= &m_ReflMmi3Table;
}