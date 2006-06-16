#ifndef _MIPSTAGS_H_
#define _MIPSTAGS_H_

#include "Types.h"
#include "List.h"

class CMIPSTags
{
public:
								CMIPSTags();
								~CMIPSTags();
	void						InsertTag(uint32, char*);
	void						RemoveTags();
	char*						Find(uint32);
	void						Serialize(char*);
	void						Unserialize(char*);

	Framework::CList<char>		m_Tag;
	
};

#endif