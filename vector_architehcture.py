
import m5
from m5 import stats
from m5.objects import * 
m5.util.addToPath("../../")
from caches import *

system = System()
system.clk_domain = SrcClockDomain()
system.clk_domain.clock = "1GHz"
system.clk_domain.voltage_domain = VoltageDomain()
system.mem_mode = "timing"  # Use timing accesses
system.mem_ranges = [AddrRange("1GB")]

# Set up RISC-V Vector CPU
system.cpu = RiscvO3CPU()()
system.cpu.createThreads()

system.cpu.icache = L1ICache()
system.cpu.dcache = L1DCache() 
system.cpu.icache.connectCPU(system.cpu)
system.cpu.dcache.connectCPU(system.cpu)

system.l2bus = L2XBar()
system.cpu.icache.connectBus(system.l2bus)
system.cpu.dcache.connectBus(system.l2bus)

system.l2cache = L2Cache()
system.l2cache.connectCPUSideBus(system.l2bus)
system.membus = SystemXBar()
system.l2cache.connectMemSideBus(system.membus)


# create the interrupt controller for the CPU
system.cpu.createInterruptController()
system.system_port = system.membus.cpu_side_ports

# Create a DDR3 memory controller
system.mem_ctrl = MemCtrl()
system.mem_ctrl.dram = DDR3_1600_8x8()
system.mem_ctrl.dram.range = system.mem_ranges[0]
system.mem_ctrl.port = system.membus.mem_side_ports

system.workload = SEWorkload.init_compatible('/Users/nischaljsh/gem5/configs/assignment5/non_loop_rolled')
process = Process()
process.cmd = ['/Users/nischaljsh/gem5/configs/assignment5/non_loop_rolled']
system.cpu.workload = process
root = Root(full_system = False, system = system)
m5.instantiate()
# Run the simulation
print("Beginning simulation!")
exit_event = m5.simulate()
print('Exiting @ tick {} because {}'
      .format(m5.curTick(), exit_event.getCause()))
