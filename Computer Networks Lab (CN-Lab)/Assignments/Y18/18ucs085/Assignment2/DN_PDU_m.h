//
// Generated file, do not edit! Created by nedtool 5.4 from DN_PDU.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __DN_PDU_M_H
#define __DN_PDU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>DN_PDU.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet DN_PDU
 * {
 *     int Mod;
 *     string type;
 * }
 * </pre>
 */
class DN_PDU : public ::omnetpp::cPacket
{
  protected:
    int Mod;
    ::omnetpp::opp_string type;

  private:
    void copy(const DN_PDU& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DN_PDU&);

  public:
    DN_PDU(const char *name=nullptr, short kind=0);
    DN_PDU(const DN_PDU& other);
    virtual ~DN_PDU();
    DN_PDU& operator=(const DN_PDU& other);
    virtual DN_PDU *dup() const override {return new DN_PDU(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getMod() const;
    virtual void setMod(int Mod);
    virtual const char * getType() const;
    virtual void setType(const char * type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DN_PDU& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DN_PDU& obj) {obj.parsimUnpack(b);}


#endif // ifndef __DN_PDU_M_H

