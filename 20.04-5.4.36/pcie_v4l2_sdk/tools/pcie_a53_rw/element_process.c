#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <byteswap.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/time.h>

#include "element_process.h"
#include "arm_pcie_protocol.h"

extern void mdelay(int ms_count);
char cmd[256];

void element_channel_process(void *BaseAddress, uint32_t channel, DATA_ELEMENT *elem, int elem_num)
{
	int i;
	uint8_t dev;
	uint16_t reg;
	uint8_t reg_h, reg_l;
	uint8_t data;
	uint8_t bits;
	uint16_t delay;
	// uint8_t rd_data = 0;

	// IIC_INIT(BaseAddress);
	// IIC_CMD_INTACK(BaseAddress);
	// mdelay(10);
	memset(cmd, 0, 256);
	sprintf(cmd, "i2cdetect -r -y %d", channel);
	send_cmd_to_a53_sync(cmd);

	for (i = 0; i < elem_num; i++)
	{
		dev = elem->dev / 2;
		reg = elem->reg;
		data = elem->data;
		bits = elem->bits;
		delay = elem->delay;

		if (bits == 0x10)
		{
			reg_h = (reg >> 8) & 0xff;
			reg_l = reg & 0xff;
			memset(cmd, 0, 256);
			sprintf(cmd, "i2ctransfer -f -y %d w3@0x%02x 0x%02x 0x%02x 0x%04x\n", channel, dev, reg_h, reg_l, data);
		}
		else if (bits == 0x08)
		{
			reg_l = reg & 0xff;
			memset(cmd, 0, 256);
			sprintf(cmd, "i2cset -f -y %d 0x%02x 0x%02x 0x%04x\n", channel, dev, reg_l, data);
		}

		send_cmd_to_a53_sync(cmd);
		printf("%s", cmd);
		usleep(delay * 1000);

		// if(rd_data !=data)
		//	printf ("Dev =%x, Reg=%x, Data=%x RD_Data=%x (%d) Check Failed!\r\n", \
		//		 dev, reg, data, rd_data, channel);
		// mdelay(delay);

		elem++;
	}

	memset(cmd, 0, 256);
	sprintf(cmd, "i2cdetect -r -y %d", channel);
	send_cmd_to_a53_sync(cmd);
}
