#ifndef __OFFICER_MSG__
#define __OFFICER_MSG__

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct OfficerOpCMsg : public PlayerMsg
{
    enum { id = 0xAF0 };

    uint32 op;
    uint64 param;
	char name[PLAYER_NAME_SIZE];
    
    OfficerOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , param(0)
    {
		bzero(name, sizeof(name));
	}
};

struct OfficerInfoSMsg : public PlayerMsg
{
    enum { id = 0xAF1 };

    OfficerProps props;

    OfficerInfoSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct OfficerListSMsg : public PlayerMsg
{
    enum { id = 0xAF2 };

    uint32	mode;				// ��ͬ�������ͣ���OfficerEnums.h 
	uint32	result;				// ������ͣ��μ�ö��OfficerOpResult(OfficerEnums.h)
	uint32	count;

    struct tagTarget 
	{
        uint64 CharId;			// ���Id
        char   Name[TINYSTR];	// ����
        uint32 LeaderCard;		// ���ͼ��
        uint32 OfficerLevel;	// ��ǰ�Ĺ��εȼ�
        uint32 Power;			// ս��
        uint32 Level;			// �ȼ�
        uint32 Renown;			// ����ֵ
        uint32 Disable;			// �Ƿ��ڱ���CD��
    } data[0];

    OfficerListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , mode(0)
		, count(0)
    {
		bzero(data, sizeof(data));
	}

	int getSize() const
	{
		return static_cast<int>(sizeof(*this) + sizeof(data[0]) * count);
	}
};

struct OfficerTotalInfoSMsg : public PlayerMsg
{
	enum { id = 0xAF3 };

	uint32 count;		// ��λ���ܸ���

	struct tagTarget
	{
		uint8	type;	// ��λ��Id(����)
		uint16	num;	// ��ǰ��λ������
	}data[0];

	OfficerTotalInfoSMsg()
		: PlayerMsg(id, sizeof(*this))
		, count(0)
	{
		bzero(data, sizeof(data));
	}

	int getSize() const
	{
		return static_cast<int>(sizeof(*this) + sizeof(data[0]) * count);
	}
};

// ָ����λ������б���Ϣ
struct OfficerPlayerListSMsg : public PlayerMsg
{
	enum { id = 0xAF4 };

	uint8	type;		// ��λ������
	uint32	count;		// ��λ���������

	struct tagTarget
	{
		uint64	id;							// ��ҵ�Id
		char	name[PLAYER_NAME_SIZE];		// �������
		uint32	playerIcon;					// ���ͼ��
		uint32	level;						// �ȼ�
		uint32	power;						// ս��
		uint32	renown;						// ����
		uint32	disable;					// �Ƿ������ս
        uint32  officerlevel;               // �پ��ȼ�
	}data[0];

	OfficerPlayerListSMsg()
		: PlayerMsg(id, sizeof(*this))
		, count(0)
	{
		bzero(data, sizeof(data));
	}

	uint16 getSize() const
	{
		return static_cast<uint16>(sizeof(*this) + sizeof(data[0]) * count);
	}
};

struct OfficerOnlineNumSMsg : public PlayerMsg
{
	enum { id = 0xAF5 };

	uint32 num;

	OfficerOnlineNumSMsg()
		: PlayerMsg(id, sizeof(*this))
		, num(0)
	{

	}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_BATTLEMSG__
