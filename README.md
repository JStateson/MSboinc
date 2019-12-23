
WARNING - USE THIS PROGRAM AT YOUR OWN RISK. If you use the bunkering feature be aware that you must only crunch the project you want to bunker and no others. Questions to josephy@stateson.net.
The sources here are based on 7.16.3 with changes to implement the following features
Usage: boinc [options]
--set_hostname <name>          use this as hostname    
--set_password <password>      rpc gui password    
--set_backoff N                set backoff to this value    
--spoof_gpus N                 fake number of gpus    
--set_bunker_cnt <project> N   bunker this many workunits for given project then quit    
--mw_bug_fix                   delay attaching output to allow new work to download (Milkyway only)
--bunker_time_string <text>    unix time cutoff for reporting - used with bunker
                               in this format exactly:  "11/24/2019T10:41:29"
This project is named master - slave as the intent is to use the project information at \ProjectData\Boinc (or /var/lib/boinc) as a master and make copies of it using an incrementing hostname, same password, and incrementing RPC port to create and run multiple clients. This is useful if a project goes offline and spoofing the number of GPUs does not provide an adaquate number of work units to continue crunching during the outage. The scripts, bash and cmd, to perform this function are under construction.


# License
BOINC is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

BOINC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with BOINC.  If not, see <https://www.gnu.org/licenses/>.
