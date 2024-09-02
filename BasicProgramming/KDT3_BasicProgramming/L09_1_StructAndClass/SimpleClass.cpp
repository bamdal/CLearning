#include "SimpleClass.h"



int CSimpleClass::AddVal()
{
	return m_iVal1 + m_iVal2;
}

void CSimpleClass::SetName(const char* lpName)
{
    // 여기도 클래스 내부
    m_strName = lpName;
}
