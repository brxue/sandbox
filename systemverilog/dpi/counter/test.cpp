#include "vpi_user.h"
#include "svdpi.h"

class counter_t
{
	public:
		counter_t()
		{
			cnt = 0;
		}
		
		void reset()
		{
			cnt = 0;
		}

		void load(unsigned char val)
		{
			cnt = val;
		}

		unsigned char get()
		{
			return cnt;
		}

		void cycle()
		{
			cnt = cnt + 1;
			cnt = cnt;
		}
	private:
		unsigned char cnt;
};

extern "C"
{
	void* counter_new()
	{
		return new counter_t();
	}
	
	void counter_reset(void* inst)
	{
		((counter_t *)inst)->reset();
	}
	
	void counter_load(void* inst, unsigned char val)
	{
		((counter_t *)inst)->load(val);
	}
	
	unsigned char counter_get(void* inst)
	{
		return ((counter_t *)inst)->get();
	}
	
	void counter_cycle(void* inst)
	{
		((counter_t *)inst)->cycle();
	}
}
