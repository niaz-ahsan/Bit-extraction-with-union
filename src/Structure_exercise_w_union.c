/*
 ==================================================================================================================
Problem Statement: Decode a 32 bit packet, extract respective bits & store them in an user defined var using union
 ==================================================================================================================
 */

#include <stdio.h>
#include <stdint.h>

union packet {
	uint32_t packet_value;
	struct {
		uint32_t crc			:2;
		uint32_t status			:1;
		uint32_t payload		:12;
		uint32_t bat			:3;
		uint32_t sensor			:3;
		uint32_t long_addr		:8;
		uint32_t short_addr		:2;
		uint32_t addr_mode		:1;
	} packet_decoder;
};

void print_packet(union packet *ptr) {
	printf("crc = %d\n", ptr->packet_decoder.crc);
	printf("status = %d\n", ptr->packet_decoder.status);
	printf("payload = %d\n", ptr->packet_decoder.payload);
	printf("bat = %d\n", ptr->packet_decoder.bat);
	printf("sensor = %d\n", ptr->packet_decoder.sensor);
	printf("long_addr = %d\n", ptr->packet_decoder.long_addr);
	printf("short_addr = %d\n", ptr->packet_decoder.short_addr);
	printf("addr_mode = %d\n", ptr->packet_decoder.addr_mode);
}

int main() {
	union packet bundle;

	printf("Enter your 32 bit packet value: ");
	scanf("%d", &bundle.packet_value);

	print_packet(&bundle);

	return 0;
}
