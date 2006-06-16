#include "LogControl.h"
#include "Config.h"

CLogControl::CLogControl()
{
	CConfig::GetInstance()->RegisterPreferenceBoolean("logging.gs",		false);
	CConfig::GetInstance()->RegisterPreferenceBoolean("logging.dmac",	false);
	CConfig::GetInstance()->RegisterPreferenceBoolean("logging.ipu",	false);
	CConfig::GetInstance()->RegisterPreferenceBoolean("logging.os",		false);

	LoadConfig();
}

CLogControl::~CLogControl()
{
	SaveConfig();
}

void CLogControl::LoadConfig()
{
	m_nGSLogging	= CConfig::GetInstance()->GetPreferenceBoolean("logging.gs");
	m_nDMACLogging	= CConfig::GetInstance()->GetPreferenceBoolean("logging.dmac");
	m_nIPULogging	= CConfig::GetInstance()->GetPreferenceBoolean("logging.ipu");
	m_nOSLogging	= CConfig::GetInstance()->GetPreferenceBoolean("logging.os");
}

void CLogControl::SaveConfig()
{
	CConfig::GetInstance()->SetPreferenceBoolean("logging.gs",		m_nGSLogging);
	CConfig::GetInstance()->SetPreferenceBoolean("logging.dmac",	m_nDMACLogging);
	CConfig::GetInstance()->SetPreferenceBoolean("logging.ipu",		m_nIPULogging);
	CConfig::GetInstance()->SetPreferenceBoolean("logging.os",		m_nOSLogging);
}

bool CLogControl::GetGSLoggingStatus()
{
	return m_nGSLogging;
}

void CLogControl::SetGSLoggingStatus(bool nStatus)
{
	m_nGSLogging = nStatus;
}

bool CLogControl::GetDMACLoggingStatus()
{
	return m_nDMACLogging;
}

void CLogControl::SetDMACLoggingStatus(bool nStatus)
{
	m_nDMACLogging = nStatus;
}

bool CLogControl::GetIPULoggingStatus()
{
	return m_nIPULogging;
}

void CLogControl::SetIPULoggingStatus(bool nStatus)
{
	m_nIPULogging = nStatus;
}

bool CLogControl::GetOSLoggingStatus()
{
	return m_nOSLogging;
}

void CLogControl::SetOSLoggingStatus(bool nStatus)
{
	m_nOSLogging = nStatus;
}