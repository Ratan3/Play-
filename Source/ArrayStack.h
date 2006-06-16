#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_

template <typename Type, unsigned int MAXSIZE = 0x100> class CArrayStack
{
public:
	CArrayStack()
	{
		Reset();
	}

	void Reset()
	{
		m_nStackPointer = MAXSIZE;
	}

	Type GetAt(unsigned int nAddress)
	{
		if(m_nStackPointer + nAddress >= MAXSIZE)
		{
			throw "Invalid Address.";
		}
		return m_nStack[m_nStackPointer + nAddress];
	}

	void SetAt(unsigned int nAddress, Type nValue)
	{
		if(m_nStackPointer + nAddress >= MAXSIZE)
		{
			throw "Invalid Address.";
		}
		m_nStack[m_nStackPointer + nAddress] = nValue;
	}

	void Push(Type nValue)
	{
		if(m_nStackPointer == 0)
		{
			throw "Stack Full.";
		}
		m_nStack[--m_nStackPointer] = nValue;
	}

	Type Pull()
	{
		if(m_nStackPointer == MAXSIZE)
		{
			throw "Stack Empty.";
		}
		return m_nStack[m_nStackPointer++];
	}

	unsigned int GetCount()
	{
		return MAXSIZE - m_nStackPointer;
	}

private:
	Type			m_nStack[MAXSIZE];
	unsigned int	m_nStackPointer;
};

#endif