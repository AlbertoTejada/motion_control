#include "Fixture.h"

/* std::unique_ptr<RteMock> Fixture::_rte; */
std::unique_ptr<SpiMock> Fixture::_spi;
std::unique_ptr<TimerMock> Fixture::_timer;
