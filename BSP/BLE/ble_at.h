#ifndef BLE_AT_H
#define BLE_AT_H
#include "main.h"
#include "stdio.h"
#include "string.h"

#include "bsp_ble.h"
#include "bsp_dbg.h"

// ָ���
typedef struct __JDY_CMD_TypeDef
{
    char* OK;
    char* add;
    char* equ;
    char* over;
    char* AT;
    char* RESET;
    char* VERSION;
    char* LADDR;
    char* NAME;
    char* PIN;
    char* TYPE;
    char* BAUD;
    char* DISC;
    char* STAT;
    char* STARTEN;
    char* ADVIN;
    char* POWR;
    char* ROLE;
    char* SLEEP;
    char* DEFAULT;
    char* INQ;
    char* STOP;
    char* CONN;
    char* CONA;
    char* BAND;
    char* CLRBAND;
    char* SRBAND;
    char* MESH;
    char* KEY;
    char* NETID;
    char* MADDR;
    char* MCLSS;
    char* FRIEND;
    char* CLRFRIEND;
    char* FRTYPE;
    char* IBUUID;
    char* MAJOR;
    char* MINOR;
    char* IBSING;
    char* ENLOG;
    char* DATA;
    char* CUIO;
    char* TGIO;
    char* FUNC;
    char* SUBTYPE;
    char* LEARN;
    char* LEAVAL;
    char* DEVCLSS;
    char* KLABEL;
    char* KLTIME;
    char* KLRSSI;
    char* ALED;
    char* RSSVAL;
    char* RSSI;
    char* RITYPE;
    char* PAISTART;
    char* GSEND;
    char* RSSVLS;
}_JDY_CMD_TypeDef;


// ����ģʽ Ĭ����5
typedef enum __ROLE
{
    Slave,
    Master,
    BLE_radio,
    iBeacon,
    iBeacon_pogopin,
    MESH,
    MESH_net,
    multiSlave,
    multiMaster,
    KeyTag
}_ROLE;

// ������ Ĭ����4  (9600bps)
typedef enum __BAUD
{
    B2400 = 2U,
    B4800 = 3U,
    B9600 = 4U,
    B19200 = 5U,
    B38400 = 6U,
    B57600 = 7U,
    B115200 = 8U
}_BAUD;

// ���书�� Ĭ����4
typedef enum __POWR
{
    n_15dbm,
    n_0dbm,
    p_2dbm,
    p_3dbm,
    p_4dbm
}_POWR;

// ��ѯ--����״̬
// MESH״̬��ֻ���������������Ļ�������²���Ч��
// �ر�˵������������ʱ�������û������Ļ���������縺��
typedef enum __STAT
{
    NotConnect,
    Connected,
    Netted,
    ConnectedAndNetted
}_STAT;

// ����˯�߻��� Ĭ����1 ������Է���jdy-25m����Ӧ����ʱ����
typedef enum __STARTEN
{
    sleep,
    weakup
}_STARTEN;

// �������״̬ Ĭ����1
typedef enum __ENLOG
{
    off,
    on
}_ENLOG;

// �Ƿ���������ӷ�ʽ Ĭ����0
typedef enum __TYPE
{
    noPIN,
    NeedPIN_without_Banding,
    NeedPIN_with_Banding
}_TYPE;


// �����豸���� Ĭ����0��·������ 1(�ն��豸)
typedef enum __MCLSS
{
    Router,     //·������֧���м̣�
    Terminal    //�ն��豸�����м̣�
}_MCLSS;

// ����״̬��
typedef enum __STATE
{
    JDY_idle,
    JDY_listening,
    JDY_datahandling
}_STATE;

// JDY���״̬����
typedef enum _JDY_StateDef
{
    JDY_OK,
    JDY_ERR,
    JDY_TMOUT,
    JDY_Waitting
}JDY_StateDef;

// JDY25�豸
typedef struct _JDY_DEVICE
{
    /******* ������; ********/
    _JDY_CMD_TypeDef  cmd;
    char        isInited;
    char        dbgflag;
    _STATE      state;

    /******* enum ���� ********/
    _ENLOG      ENLOG;      //�������״̬    
    _TYPE       TYPE;       //�Ƿ���ҪPIN
    _BAUD       BAUD;       //������        // Ĭ�� B9600
    _MCLSS      MCLSS;      //�����豸����
    _ROLE       ROLE;       //����ģʽ����
    _POWR       POWR;       //���书��
    _STAT       STAT;       //��ȡ����״̬

    /******* char* ���� ********/
    // ����һλ���� �ַ��� ��ĩβ�� '\0'
    char        LADDR[49];  //MAC��ַ
    char    	MADDR[5];   //�̵�ַ
    char    	NETID[5];   //����ID        // "1189"  
    char        NAME[19];   //�㲥����      // "JDY-25M"
    char        PIN[7];     //����PIN       // "123456"
    
}JDY_Def;




#define JAY_MAX_AT_SIZE       ((uint16_t)49U)
#define JAY_MAX_Para_SIZE     ((uint16_t)49U)
#define JAY_MAX_Recv_SIZE     ble_MAX_datarev_buffsize
#define JDY_Listening_timeout   ((uint32_t)3000U)   // ���ʱ1000ms


extern JDY_Def JDY;

JDY_StateDef __jdy_AT_OKcheck(void);
JDY_StateDef __jdy_AT_CMD(const char* cmdin, const char* param);
JDY_StateDef __jdy_AT_Query(const char* cmdin, char* param, size_t paramlen);
JDY_StateDef __jdy_AT_Query_with_enum(const char* cmdin, int* num);
JDY_StateDef __jdy_AT_Query_with_char(const char* cmdin, char* c, size_t paramlen);
JDY_StateDef __jdy_AT_Query_Selectable(const  char* cmdin);
void __jdy_StrCut(char* str, size_t len);

JDY_StateDef jdy_SNED_and_EQUERY(const char* cmdin, const char* param);
JDY_StateDef jdy_SEND_CMD(const char *cmdin, const char *param);
JDY_StateDef jdy_SEND_MESH(const char* data);
JDY_StateDef jdy_EQUERY(const char* cmdin);

void jdy_init(void);
void jdy_loop(void);
void jdy_it_ble_handle(void);
void jdy_it_dbg_handle(void);



// void _jdy_txData_cat(const char* cmdin);

#endif
