#include <stdint.h>

class SystemModel
{
	public:
		/* SystemModel(float wn, float dp); */
		SystemModel(float K, float tau);
		~SystemModel();
		int32_t system_response(uint32_t dtime, int32_t input);	
		uint32_t t0;
	private:
		float K;
		float tau;
		/* float wn; */
		/* float dp; */
		/* float beta; */
		/* float teta; */
		float p0;
};
