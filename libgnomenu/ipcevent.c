#include <config.h>
#include <glib.h>
#include "ipccommand.h"
#include "ipcevent.h"

IPCEvent * ipc_event_parse(const gchar * string) {
	return ipc_command_parse(string);
}
IPCEvent * ipc_event_new(const gchar * cid, const gchar * name) {
	return ipc_command_new(cid, name);
}
void ipc_event_free(IPCEvent * event) {
	ipc_command_free(event);
}
gchar * ipc_event_to_string(IPCEvent * event){
	return ipc_command_to_string(event);
}
void ipc_event_set_parameters(IPCEvent * event, gchar * para_name, ...){
	va_list va;
	va_start(va, para_name);
	ipc_event_set_parameters_valist(event, para_name, va);
	va_end(va);
}
void ipc_event_set_parameters_valist(IPCEvent * event, gchar * para_name, va_list va) {
	ipc_command_set_parameters_valist(event, para_name, va);
}