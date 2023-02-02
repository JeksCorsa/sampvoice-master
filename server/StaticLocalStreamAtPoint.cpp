/*
	This is a SampVoice project file
	Developer: CyberMor <cyber.mor.2020@gmail.ru>

	See more here https://github.com/CyberMor/sampvoice

	Copyright (c) Daniel (CyberMor) 2020 All rights reserved
*/

#include "StaticLocalStreamAtPoint.h"

#include <string.h>

#include "ControlPacket.h"
#include "Header.h"

StaticLocalStreamAtPoint::StaticLocalStreamAtPoint(
	const float distance, const CVector& position,
	const uint32_t color, const std::string& name
) :
	LocalStream(distance),
	PointStream(distance, position)
{

	const auto nameString = name.c_str();
	const auto nameLength = name.size() + 1;

	if (PackWrap(this->packetCreateStream, SV::ControlPacketType::createLPStream, sizeof(SV::CreateLPStreamPacket) + nameLength)) {

		PackGetStruct(&*this->packetCreateStream, SV::CreateLPStreamPacket)->stream = (uint32_t)(static_cast<Stream*>(this));
		memcpy(PackGetStruct(&*this->packetCreateStream, SV::CreateLPStreamPacket)->name, nameString, nameLength);
		PackGetStruct(&*this->packetCreateStream, SV::CreateLPStreamPacket)->distance = distance;
		PackGetStruct(&*this->packetCreateStream, SV::CreateLPStreamPacket)->position = position;
		PackGetStruct(&*this->packetCreateStream, SV::CreateLPStreamPacket)->color = color;

	}

}