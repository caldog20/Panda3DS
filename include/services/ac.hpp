#pragma once
#include "helpers.hpp"
#include "kernel_types.hpp"
#include "logger.hpp"
#include "memory.hpp"
#include "result/result.hpp"

class ACService {
	Handle handle = KernelHandles::AC;
	Memory& mem;
	MAKE_LOG_FUNCTION(log, acLogger)

	// Service commands
	void cancelConnectAsync(u32 messagePointer);
	void closeAsync(u32 messagePointer);
	void createDefaultConfig(u32 messagePointer);
	void getLastErrorCode(u32 messagePointer);
	void registerDisconnectEvent(u32 messagePointer);
	void setClientVersion(u32 messagePointer);

public:
	ACService(Memory& mem) : mem(mem) {}
	void reset();
	void handleSyncRequest(u32 messagePointer);
};