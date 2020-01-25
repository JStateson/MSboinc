WARNING - USE THIS PROGRAM AT YOUR OWN RISK. If you use the bunkering feature be aware
that you must only crunch the project you want to bunker and no others. Questions to josephy@stateson.net.
The sources here are based on 7.16.3 with changes to implement the following features

Usage: boinc [options]

--set_hostname <name>          use this as hostname
  
--set_password <password>      rpc gui password
  
--set_backoff N                set backoff to this value

--spoof_gpus N                 fake number of gpus but app_config spoofing takes precedence

--set_bunker_cnt <project> N   bunker this many workunits for given project then quit
  
--mw_bug_fix                   delay attaching output to allow new work to download (Milkyway only)

--bunker_time_string <text>    unix time cutoff for reporting in this format exactly:  "11/24/2019T10:41:29"
                               
Filtering of project messages uses new features in cc_config.xml and allows for hiding messages that obscure the
limited amount of space visible in the event log.  See cc_config.xml for a sample filter that eliminates most
of the ignoreable message like "no work available for xxx" or "boinc deleted yyy".  In addtion, some non-project
messages such as "Backing off" are displayed only when the projet name changes.
                               
This project is named master - slave as the intent is to use the project information at \ProjectData\Boinc
(or /var/lib/boinc) as a master and make copies of it using an incrementing hostname, same password, and
incrementing RPC port to create and run multiple clients. This is useful if a project goes offline and
spoofing the number of GPUs does not provide an adaquate number of work units to continue crunching during
the outage. The scripts, bash and cmd, to perform this function are under construction.

The Milkyway bug fix is automatically enabled if the following debug flag is created
<mw_debug>1<mw_debug>.  This allows the MW project to constantly get data and avoid the 10 minute delay
<spoof_gpus>16</spoof_gps> requests data from the spcified project sufficient for 16 GPUs.  Can be
applied to specfic projects, or all projects.  Version now gives the build date and time.
1-15-2020: now correlating busid and boinc id to the coprocessor board for better identificiation

Manu  Boinc  Manu   BusID     Board

 ID    ID    Name   (hex)     Name
 
  0     5    NV   01:00.0    GTX-1070
	
  1     0    NV   02:00.0    GTX-1660-Ti
	
  2     1    NV   03:00.0    P102-100
	
  3     2    NV   04:00.0    P102-100
	
  4     3    NV   05:00.0    P102-100
	
  5     4    NV   06:00.0    GTX-1070-Ti
