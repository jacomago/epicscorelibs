/** @file lsiRecord.h
 * @brief Declarations for the @ref lsiRecord "lsi" record type.
 *
 * This header was generated from lsiRecord.dbd
 */

#ifndef INC_lsiRecord_H
#define INC_lsiRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "devSup.h"
#include "epicsTime.h"

/* Declare Device Support Entry Table */
struct lsiRecord;
typedef struct lsidset {
    dset common;
    long (*read_string)(struct lsiRecord *prec);
} lsidset;
#define HAS_lsidset

#include "callback.h"

/** @brief Declaration of lsi record type. */
typedef struct lsiRecord {
    char                name[61];   /**< @brief Record Name */
    char                desc[41];   /**< @brief Descriptor */
    char                asg[29];    /**< @brief Access Security Group */
    epicsEnum16         scan;       /**< @brief Scan Mechanism */
    epicsEnum16         pini;       /**< @brief Process at iocInit */
    epicsInt16          phas;       /**< @brief Scan Phase */
    char                evnt[40];   /**< @brief Event Name */
    epicsInt16          tse;        /**< @brief Time Stamp Event */
    DBLINK              tsel;       /**< @brief Time Stamp Link */
    epicsEnum16         dtyp;       /**< @brief Device Type */
    epicsInt16          disv;       /**< @brief Disable Value */
    epicsInt16          disa;       /**< @brief Disable */
    DBLINK              sdis;       /**< @brief Scanning Disable */
    epicsMutexId        mlok;       /**< @brief Monitor lock */
    ELLLIST             mlis;       /**< @brief Monitor List */
    ELLLIST             bklnk;      /**< @brief Backwards link tracking */
    epicsUInt8          disp;       /**< @brief Disable putField */
    epicsUInt8          proc;       /**< @brief Force Processing */
    epicsEnum16         stat;       /**< @brief Alarm Status */
    epicsEnum16         sevr;       /**< @brief Alarm Severity */
    char                amsg[40];   /**< @brief Alarm Message */
    epicsEnum16         nsta;       /**< @brief New Alarm Status */
    epicsEnum16         nsev;       /**< @brief New Alarm Severity */
    char                namsg[40];  /**< @brief New Alarm Message */
    epicsEnum16         acks;       /**< @brief Alarm Ack Severity */
    epicsEnum16         ackt;       /**< @brief Alarm Ack Transient */
    epicsEnum16         diss;       /**< @brief Disable Alarm Sevrty */
    epicsUInt8          lcnt;       /**< @brief Lock Count */
    epicsUInt8          pact;       /**< @brief Record active */
    epicsUInt8          putf;       /**< @brief dbPutField process */
    epicsUInt8          rpro;       /**< @brief Reprocess  */
    struct asgMember    *asp;       /**< @brief Access Security Pvt */
    struct processNotify *ppn;      /**< @brief pprocessNotify */
    struct processNotifyRecord *ppnr; /**< @brief pprocessNotifyRecord */
    struct scan_element *spvt;      /**< @brief Scan Private */
    struct typed_rset   *rset;      /**< @brief Address of RSET */
    unambiguous_dset    *dset;      /**< @brief DSET address */
    void                *dpvt;      /**< @brief Device Private */
    struct dbRecordType *rdes;      /**< @brief Address of dbRecordType */
    struct lockRecord   *lset;      /**< @brief Lock Set */
    epicsEnum16         prio;       /**< @brief Scheduling Priority */
    epicsUInt8          tpro;       /**< @brief Trace Processing */
    epicsUInt8          bkpt;       /**< @brief Break Point */
    epicsUInt8          udf;        /**< @brief Undefined */
    epicsEnum16         udfs;       /**< @brief Undefined Alarm Sevrty */
    epicsTimeStamp      time;       /**< @brief Time */
    epicsUInt64         utag;       /**< @brief Time Tag */
    DBLINK              flnk;       /**< @brief Forward Process Link */
    char *val;                      /**< @brief Current Value */
    char *oval;                     /**< @brief Old Value */
    epicsUInt16         sizv;       /**< @brief Size of buffers */
    epicsUInt32         len;        /**< @brief Length of VAL */
    epicsUInt32         olen;       /**< @brief Length of OVAL */
    DBLINK              inp;        /**< @brief Input Specification */
    epicsEnum16         mpst;       /**< @brief Post Value Monitors */
    epicsEnum16         apst;       /**< @brief Post Archive Monitors */
    DBLINK              siml;       /**< @brief Simulation Mode Link */
    epicsEnum16         simm;       /**< @brief Simulation Mode */
    epicsEnum16         sims;       /**< @brief Simulation Mode Severity */
    DBLINK              siol;       /**< @brief Simulation Input Link */
    epicsEnum16         oldsimm;    /**< @brief Prev. Simulation Mode */
    epicsEnum16         sscn;       /**< @brief Sim. Mode Scan */
    epicsFloat64        sdly;       /**< @brief Sim. Mode Async Delay */
    epicsCallback            *simpvt; /**< @brief Sim. Mode Private */
} lsiRecord;

typedef enum {
	lsiRecordNAME = 0,
	lsiRecordDESC = 1,
	lsiRecordASG = 2,
	lsiRecordSCAN = 3,
	lsiRecordPINI = 4,
	lsiRecordPHAS = 5,
	lsiRecordEVNT = 6,
	lsiRecordTSE = 7,
	lsiRecordTSEL = 8,
	lsiRecordDTYP = 9,
	lsiRecordDISV = 10,
	lsiRecordDISA = 11,
	lsiRecordSDIS = 12,
	lsiRecordMLOK = 13,
	lsiRecordMLIS = 14,
	lsiRecordBKLNK = 15,
	lsiRecordDISP = 16,
	lsiRecordPROC = 17,
	lsiRecordSTAT = 18,
	lsiRecordSEVR = 19,
	lsiRecordAMSG = 20,
	lsiRecordNSTA = 21,
	lsiRecordNSEV = 22,
	lsiRecordNAMSG = 23,
	lsiRecordACKS = 24,
	lsiRecordACKT = 25,
	lsiRecordDISS = 26,
	lsiRecordLCNT = 27,
	lsiRecordPACT = 28,
	lsiRecordPUTF = 29,
	lsiRecordRPRO = 30,
	lsiRecordASP = 31,
	lsiRecordPPN = 32,
	lsiRecordPPNR = 33,
	lsiRecordSPVT = 34,
	lsiRecordRSET = 35,
	lsiRecordDSET = 36,
	lsiRecordDPVT = 37,
	lsiRecordRDES = 38,
	lsiRecordLSET = 39,
	lsiRecordPRIO = 40,
	lsiRecordTPRO = 41,
	lsiRecordBKPT = 42,
	lsiRecordUDF = 43,
	lsiRecordUDFS = 44,
	lsiRecordTIME = 45,
	lsiRecordUTAG = 46,
	lsiRecordFLNK = 47,
	lsiRecordVAL = 48,
	lsiRecordOVAL = 49,
	lsiRecordSIZV = 50,
	lsiRecordLEN = 51,
	lsiRecordOLEN = 52,
	lsiRecordINP = 53,
	lsiRecordMPST = 54,
	lsiRecordAPST = 55,
	lsiRecordSIML = 56,
	lsiRecordSIMM = 57,
	lsiRecordSIMS = 58,
	lsiRecordSIOL = 59,
	lsiRecordOLDSIMM = 60,
	lsiRecordSSCN = 61,
	lsiRecordSDLY = 62,
	lsiRecordSIMPVT = 63
} lsiFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int lsiRecordSizeOffset(dbRecordType *prt)
{
    lsiRecord *prec = 0;

    if (prt->no_fields != 64) {
        cantProceed("IOC build or installation error:\n"
            "    The lsiRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 64.\n",
            prt->no_fields);
    }
    prt->papFldDes[lsiRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[lsiRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[lsiRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[lsiRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[lsiRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[lsiRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[lsiRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[lsiRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[lsiRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[lsiRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[lsiRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[lsiRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[lsiRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[lsiRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[lsiRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[lsiRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[lsiRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[lsiRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[lsiRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[lsiRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[lsiRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[lsiRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[lsiRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[lsiRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[lsiRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[lsiRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[lsiRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[lsiRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[lsiRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[lsiRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[lsiRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[lsiRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[lsiRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[lsiRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[lsiRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[lsiRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[lsiRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[lsiRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[lsiRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[lsiRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[lsiRecordAMSG]->size = sizeof(prec->amsg);
    prt->papFldDes[lsiRecordAMSG]->offset = (unsigned short)((char *)&prec->amsg - (char *)prec);
    prt->papFldDes[lsiRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[lsiRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[lsiRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[lsiRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[lsiRecordNAMSG]->size = sizeof(prec->namsg);
    prt->papFldDes[lsiRecordNAMSG]->offset = (unsigned short)((char *)&prec->namsg - (char *)prec);
    prt->papFldDes[lsiRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[lsiRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[lsiRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[lsiRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[lsiRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[lsiRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[lsiRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[lsiRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[lsiRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[lsiRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[lsiRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[lsiRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[lsiRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[lsiRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[lsiRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[lsiRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[lsiRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[lsiRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[lsiRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[lsiRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[lsiRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[lsiRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[lsiRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[lsiRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[lsiRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[lsiRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[lsiRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[lsiRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[lsiRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[lsiRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[lsiRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[lsiRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[lsiRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[lsiRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[lsiRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[lsiRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[lsiRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[lsiRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[lsiRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[lsiRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[lsiRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[lsiRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[lsiRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[lsiRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[lsiRecordUTAG]->size = sizeof(prec->utag);
    prt->papFldDes[lsiRecordUTAG]->offset = (unsigned short)((char *)&prec->utag - (char *)prec);
    prt->papFldDes[lsiRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[lsiRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[lsiRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[lsiRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[lsiRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[lsiRecordOVAL]->offset = (unsigned short)((char *)&prec->oval - (char *)prec);
    prt->papFldDes[lsiRecordSIZV]->size = sizeof(prec->sizv);
    prt->papFldDes[lsiRecordSIZV]->offset = (unsigned short)((char *)&prec->sizv - (char *)prec);
    prt->papFldDes[lsiRecordLEN]->size = sizeof(prec->len);
    prt->papFldDes[lsiRecordLEN]->offset = (unsigned short)((char *)&prec->len - (char *)prec);
    prt->papFldDes[lsiRecordOLEN]->size = sizeof(prec->olen);
    prt->papFldDes[lsiRecordOLEN]->offset = (unsigned short)((char *)&prec->olen - (char *)prec);
    prt->papFldDes[lsiRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[lsiRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[lsiRecordMPST]->size = sizeof(prec->mpst);
    prt->papFldDes[lsiRecordMPST]->offset = (unsigned short)((char *)&prec->mpst - (char *)prec);
    prt->papFldDes[lsiRecordAPST]->size = sizeof(prec->apst);
    prt->papFldDes[lsiRecordAPST]->offset = (unsigned short)((char *)&prec->apst - (char *)prec);
    prt->papFldDes[lsiRecordSIML]->size = sizeof(prec->siml);
    prt->papFldDes[lsiRecordSIML]->offset = (unsigned short)((char *)&prec->siml - (char *)prec);
    prt->papFldDes[lsiRecordSIMM]->size = sizeof(prec->simm);
    prt->papFldDes[lsiRecordSIMM]->offset = (unsigned short)((char *)&prec->simm - (char *)prec);
    prt->papFldDes[lsiRecordSIMS]->size = sizeof(prec->sims);
    prt->papFldDes[lsiRecordSIMS]->offset = (unsigned short)((char *)&prec->sims - (char *)prec);
    prt->papFldDes[lsiRecordSIOL]->size = sizeof(prec->siol);
    prt->papFldDes[lsiRecordSIOL]->offset = (unsigned short)((char *)&prec->siol - (char *)prec);
    prt->papFldDes[lsiRecordOLDSIMM]->size = sizeof(prec->oldsimm);
    prt->papFldDes[lsiRecordOLDSIMM]->offset = (unsigned short)((char *)&prec->oldsimm - (char *)prec);
    prt->papFldDes[lsiRecordSSCN]->size = sizeof(prec->sscn);
    prt->papFldDes[lsiRecordSSCN]->offset = (unsigned short)((char *)&prec->sscn - (char *)prec);
    prt->papFldDes[lsiRecordSDLY]->size = sizeof(prec->sdly);
    prt->papFldDes[lsiRecordSDLY]->offset = (unsigned short)((char *)&prec->sdly - (char *)prec);
    prt->papFldDes[lsiRecordSIMPVT]->size = sizeof(prec->simpvt);
    prt->papFldDes[lsiRecordSIMPVT]->offset = (unsigned short)((char *)&prec->simpvt - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(lsiRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_lsiRecord_H */
