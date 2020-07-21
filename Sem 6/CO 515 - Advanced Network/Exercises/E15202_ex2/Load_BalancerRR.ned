//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package openflow.scenarios;

import inet.nodes.ethernet.EtherSwitch;
import inet.nodes.inet.Router;
import inet.nodes.inet.StandardHost;
import inet.networklayer.autorouting.ipv4.FlatNetworkConfigurator;
import inet.util.ThruputMeteringChannel;

import openflow.nodes.*;


network Load_BalancerRR
{
    @display("bgb=830,358");

    types:
        channel ethernetline extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 100Mbps;
            thruputDisplayFormat = "u";
        }
    submodules:
        client1: StandardHost {
            @display("p=324,40");
        }
        server1: StandardHost {
            @display("p=498,79");
        }
        configurator: FlatNetworkConfigurator {
            parameters:
                @display("p=57,17");
        }
        open_flow_switch: Open_Flow_Switch {
            @display("p=301,157");
        }
        controller: Open_Flow_Controller {
            @display("p=391,30");
        }

        server2: StandardHost {
            @display("p=517,144");
        }
        server3: StandardHost {
            @display("p=525,217");
        }
        open_flow_switch1: Open_Flow_Switch {
            @display("p=425,158");
        }
        client2: StandardHost {
            @display("p=285,40");
        }
        client3: StandardHost {
            @display("p=246,25");
        }
        client4: StandardHost {
            @display("p=201,25");
        }
        client5: StandardHost {
            @display("p=156,25");
        }
        client6: StandardHost {
            @display("p=117,68");
        }
        client7: StandardHost {
            @display("p=78,107");
        }
        client8: StandardHost {
            @display("p=51,158");
        }
        client9: StandardHost {
            @display("p=51,217");
        }
        client10: StandardHost {
            @display("p=39,278");
        }
        client11: StandardHost {
            @display("p=84,296");
        }
        client12: StandardHost {
            @display("p=133,296");
        }
        client13: StandardHost {
            @display("p=178,296");
        }
        client14: StandardHost {
            @display("p=227,296");
        }
        client15: StandardHost {
            @display("p=276,296");
        }
        client16: StandardHost {
            @display("p=324,296");
        }
        client17: StandardHost {
            @display("p=369,290");
        }
        client18: StandardHost {
            @display("p=369,239");
        }
    connections allowunconnected:

//        client1.ethg++ <--> {delay=1ms;} <--> open_flow_switch.ethg++;
//        open_flow_switch.ethg++ <--> {delay=1ms;} <--> server1.ethg++;
//        controller.ethg++ <--> {delay=1ms;} <--> open_flow_switch.gate_controller++;
//        open_flow_switch.ethg++ <--> {delay=1ms;} <--> server2.ethg++;
//        open_flow_switch.ethg++ <--> {delay=1ms;} <--> server3.ethg++;

        client1.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client2.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client3.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client4.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client5.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client6.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client7.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client8.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client9.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client10.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client11.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client12.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client13.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client14.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client15.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client16.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client17.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        client18.ethg++ <--> ethernetline <--> open_flow_switch.ethg++;
        open_flow_switch1.ethg++ <--> ethernetline <--> server1.ethg++;
        open_flow_switch1.ethg++ <--> ethernetline <--> server2.ethg++;
        open_flow_switch1.ethg++ <--> ethernetline <--> server3.ethg++;
        controller.ethg++ <--> ethernetline <--> open_flow_switch.gate_controller++;
        controller.ethg++ <--> ethernetline <--> open_flow_switch1.gate_controller++;
        open_flow_switch.ethg++ <--> ethernetline <--> open_flow_switch1.ethg++;
}
