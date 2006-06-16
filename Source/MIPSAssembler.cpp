#include "MIPSAssembler.h"

CMIPSAssembler::CMIPSAssembler(uint32* pPtr)
{
	m_pPtr = pPtr;
}

CMIPSAssembler::~CMIPSAssembler()
{

}

void CMIPSAssembler::ADDIU(unsigned int nRT, unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x09) << 26) | (nRS << 21) | (nRT << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::ADDU(unsigned int nRD, unsigned int nRS, unsigned int nRT)
{
	(*m_pPtr) = (nRS << 21)  | (nRT << 16) | (nRD << 11) | (0x21);
	m_pPtr++;
}

void CMIPSAssembler::AND(unsigned int nRD, unsigned int nRS, unsigned int nRT)
{
	(*m_pPtr) = (nRS << 21)  | (nRT << 16) | (nRD << 11) | (0x24);
	m_pPtr++;
}

void CMIPSAssembler::ANDI(unsigned int nRT, unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x0C) << 26) | (nRS << 21) | (nRT << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::BEQ(unsigned int nRT, unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x04) << 26) | (nRS << 21) | (nRT << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::BGEZ(unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x01) << 26) | (nRS << 21) | ((0x01) << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::BGTZ(unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x07) << 26) | (nRS << 21) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::BNE(unsigned int nRT, unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x05) << 26) | (nRS << 21) | (nRT << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::BLEZ(unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x06) << 26) | (nRS << 21) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::BLTZ(unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x01) << 26) | (nRS << 21) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::DADDU(unsigned int nRD, unsigned int nRS, unsigned int nRT)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | (0x2D);
	m_pPtr++;
}

void CMIPSAssembler::DADDIU(unsigned int nRT, unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x19) << 26) | (nRS << 21) | (nRT << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::DSLL(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x38;
	m_pPtr++;
}

void CMIPSAssembler::DSLL32(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x3C;
	m_pPtr++;
}

void CMIPSAssembler::DSLLV(unsigned int nRD, unsigned int nRT, unsigned int nRS)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | 0x14;
	m_pPtr++;
}

void CMIPSAssembler::DSRA(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x3B;
	m_pPtr++;
}

void CMIPSAssembler::DSRA32(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x3F;
	m_pPtr++;
}

void CMIPSAssembler::DSRAV(unsigned int nRD, unsigned int nRT, unsigned int nRS)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | 0x17;
	m_pPtr++;
}

void CMIPSAssembler::DSRL(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x3A;
	m_pPtr++;
}

void CMIPSAssembler::DSRL32(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x3E;
	m_pPtr++;
}

void CMIPSAssembler::DSRLV(unsigned int nRD, unsigned int nRT, unsigned int nRS)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | 0x16;
	m_pPtr++;
}

void CMIPSAssembler::DSUBU(unsigned int nRD, unsigned int nRS, unsigned int nRT)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | (0x2F);
	m_pPtr++;
}

void CMIPSAssembler::ERET()
{
	(*m_pPtr) = 0x42000018;
	m_pPtr++;
}

void CMIPSAssembler::JALR(unsigned int nRS, unsigned int nRD)
{
	(*m_pPtr) = (nRS << 21) | (nRD << 11) | (0x09);
	m_pPtr++;
}

void CMIPSAssembler::JR(unsigned int nRS)
{
	(*m_pPtr) = (nRS << 21) | (0x08);
	m_pPtr++;
}

void CMIPSAssembler::LD(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x37) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::LDL(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x1A) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::LDR(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x1B) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::LUI(unsigned int nRT, uint16 nImmediate)
{
	(*m_pPtr) = ((0x0F) << 26) | (nRT << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::LQ(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x1E) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::LW(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x23) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::LWL(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x22) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::LWR(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x26) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::MFC0(unsigned int nRT, unsigned int nRD)
{
	(*m_pPtr) = ((0x10) << 26) | (nRT << 16) | (nRD << 11);
	m_pPtr++;
}

void CMIPSAssembler::MTC0(unsigned int nRT, unsigned int nRD)
{
	(*m_pPtr) = ((0x10) << 26) | ((0x04) << 21) | (nRT << 16) | (nRD << 11);
	m_pPtr++;
}

void CMIPSAssembler::MULTU(unsigned int nRS, unsigned int nRT, unsigned int nRD)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | 0x19;
	m_pPtr++;
}

void CMIPSAssembler::NOP()
{
	(*m_pPtr) = 0;
	m_pPtr++;
}

void CMIPSAssembler::ORI(unsigned int nRT, unsigned int nRS, uint16 nImmediate)
{
	(*m_pPtr) = ((0x0D) << 26) | (nRS << 21) | (nRT << 16) | nImmediate;
	m_pPtr++;
}

void CMIPSAssembler::SD(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x3F) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::SLL(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6);
	m_pPtr++;
}

void CMIPSAssembler::SLLV(unsigned int nRD, unsigned int nRT, unsigned int nRS)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | 0x04;
	m_pPtr++;
}

void CMIPSAssembler::SRA(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x03;
	m_pPtr++;
}

void CMIPSAssembler::SRAV(unsigned int nRD, unsigned int nRT, unsigned int nRS)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | 0x07;
	m_pPtr++;
}

void CMIPSAssembler::SRL(unsigned int nRD, unsigned int nRT, unsigned int nSA)
{
	nSA &= 0x1F;
	(*m_pPtr) = (nRT << 16) | (nRD << 11) | (nSA << 6) | 0x02;
	m_pPtr++;
}

void CMIPSAssembler::SRLV(unsigned int nRD, unsigned int nRT, unsigned int nRS)
{
	(*m_pPtr) = (nRS << 21) | (nRT << 16) | (nRD << 11) | 0x06;
	m_pPtr++;
}

void CMIPSAssembler::SQ(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x1F) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::SW(unsigned int nRT, uint16 nOffset, unsigned int nBase)
{
	(*m_pPtr) = ((0x2B) << 26) | (nBase << 21) | (nRT << 16) | nOffset;
	m_pPtr++;
}

void CMIPSAssembler::SYSCALL()
{
	(*m_pPtr) = 0x0000000C;
	m_pPtr++;
}