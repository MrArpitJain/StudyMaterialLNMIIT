//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Node.h"
#include <N_PDU_m.h>
Define_Module(Node);

double ms=0;
void Node::inc()
{
    i++;
}
void Node::initialize()
{
    // TODO - Generated method body
    address=par("id");
    srcadd=par("SA");
    desadd=par("DA");
    /*for(int i=0;i<3;i++)
    {
        in[i]=gate("gIN[i]");
        out[i]=gate("gOUT[i]");
    }*/
    switch(address)
    {
    case 0:
        forwardingTable={{1,1},{2,0},{3,0},{4,0}};
        break;
    case 1:
        forwardingTable={{0,0},{2,1},{3,1},{4,1}};
        break;
    case 2:
        forwardingTable={{0,1},{1,0},{3,2},{4,2}};
        break;
    case 3:
        forwardingTable={{0,0},{1,0},{2,0},{4,1}};
        break;
    case 4:
        forwardingTable={{0,0},{1,0},{2,0},{3,0}};
        break;
    }
    if(address==srcadd)
    {
        EV << "Message going towards " << desadd << "from " << address<<"\n";
        cMessage *msg=new cMessage();
        scheduleAt(0,msg);
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->isSelfMessage())
    {
        N_PDU * npkt = new N_PDU();
        npkt->setMid(i);
        inc();
        //npkt->setType("Data");
        npkt->setSAdd(desadd);
        npkt->setDAdd(desadd);
        npkt->setTime(SimTime());
        send(npkt,"gOUT",forwardingTable.at(desadd));
    }
    else
    {
        N_PDU * npkt = check_and_cast <N_PDU *> (msg);
        if(npkt->getDAdd()==address)
        {
            ms=simTime().dbl()*1000;
            EV << "Message successfully received at destination at time "<< ms << "ms\n";
            delete(npkt);
        }
        else
        {
            EV << "Message going towards " << desadd << "from " << address<<"\n";
            send(npkt,"gOUT",forwardingTable.at(desadd));
        }
    }
}
