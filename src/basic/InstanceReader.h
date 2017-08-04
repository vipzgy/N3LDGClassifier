#ifndef _CONLL_READER_
#define _CONLL_READER_

#include "Reader.h"
#include "N3LDG.h"
#include <sstream>

using namespace std;
/*
 this class reads conll-format data (10 columns, no srl-info)
 */
class InstanceReader : public Reader {
public:
	InstanceReader() {
	}
	~InstanceReader() {
	}

	Instance *getNext() {
		m_instance.clear();
		string strLine1;
		if (!my_getline(m_inf, strLine1))
			return NULL;
		if (strLine1.empty())
			return NULL;


		vector<string> vecInfo;
		split_bychars(strLine1, vecInfo, "|||");
		m_instance.m_label = vecInfo[vecInfo.size() - 1];

		split_bychar(vecInfo[0], m_instance.m_words, ' ');
		return &m_instance;
	}
};

#endif

