uint32_t FilterDigits(uint32_t N, enum FilterAction action, uint8_t pivot) {
   
   if (pivot == 0){
	if (action == LOFIRST){
		return N;
	}
	else {
		return N * 10;
	}
   }

	//variable for result 
	uint32_t result = 0;
	//variable for high and low part and possible middle
	uint32_t high_part = 0;
	uint32_t low_part = 0;
	uint32_t middle = 0;
	
	//value to manipulate
	uint32_t value = N;
	
	//powers of ten for high and low part
	uint32_t h_tens = 1;
	uint32_t l_tens = 1;
	uint32_t s_tens = 1;

	//run until no more digits left to filter
	while(value > 0){
		//get current digit, compare to pivot, add to part
		uint8_t digit = value % 10;
		if (digit > pivot){
			high_part = high_part + (digit * h_tens);
			h_tens *= 10;
		}
		if (digit < pivot){
			low_part = low_part + (digit * l_tens);
			l_tens *= 10;
		}
		if (digit == pivot){
		middle = middle + (digit * s_tens);
		s_tens *= 10;
		}
		value = value / 10;
	}


	if (action == HIFIRST){
	high_part = (high_part * s_tens) + middle;
	result = (high_part * l_tens) + low_part;
	}   
	else {
		low_part = (low_part * s_tens) + middle;
		result = (low_part * h_tens) + high_part;
	}
   	return result;
}
