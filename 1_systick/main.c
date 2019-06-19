#include <stdint.h>
#include "reg.h"
#include "blink.h"

void setup_systick(uint32_t ticks);

int main(void)
{
	setup_systick(168e6/8/5); //200 ms
	blink(LED_BLUE); //should not return
}

void setup_systick(uint32_t ticks)
{
	// set reload value
    WRITE_BITS(SYST_BASE + SYST_RVR_OFFSET ,23,0,ticks-1  );
	// uses external reference clock
	

	// enable systick exception
	

	// enable systick
	REG(SYST_BASE +SYST_CSR_OFFSET )=3;
}

void systick_handler(void)
{
	blink_count(LED_ORANGE, 1);
}
