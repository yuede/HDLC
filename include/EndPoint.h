/*
 * EndPoint.h
 *
 *  Created on: Sep 23, 2015
 *      Author: peter
 */

#ifndef ENDPOINT_H_
#define ENDPOINT_H_

#include <Thread.h>

#include "EscapingSource.h"
#include "FrameReceiver.h"
#include "FrameTransmitter.h"
#include "EscapingSink.h"
#include "FrameHandler.h"

namespace hdlc {

class EndPoint: public Thread, public FrameHandler {
	EscapingSource& source;
	FrameReceiver& receiver;
	FrameHandler& handler;
	FrameBuffer& outgoingFrameBuffer;
	FrameTransmitter& transmitter;
	EscapingSink& sink;
	SequenceNumber expectedSequenceNumber;

protected:
	PT_THREAD(run());

public:
	EndPoint(EscapingSource&, FrameReceiver&, FrameHandler&, FrameBuffer&, FrameTransmitter&, EscapingSink&);
	virtual ~EndPoint();

	virtual void handle(const uint8_t, const uint8_t*, const uint8_t);
};

} /* namespace hdlc */

#endif /* ENDPOINT_H_ */
