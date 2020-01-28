**WARNING: USE THIS PROGRAM AT YOUR OWN RISK,  The executable is NOT in this project, you must built it**

**If you find an executable on the internet that seems be be from here, DO NOT USE IT as it is not from here**

The sources here are based on 7.16.3 with changes to implement the following features
```
Usage: boinc [options]
--set_hostname <name>          use this as hostname  
--set_password <password>      rpc gui password
--set_backoff N                set backoff to this value
--spoof_gpus N                 fake number of gpus but app_config spoofing takes precedence
--set_bunker_cnt <project> N   bunker this many workunits for given project then quit  
--mw_bug_fix                   delay attaching output to allow new work to download (Milkyway only)
--bunker_time_string <text>    unix time cutoff for reporting in this format exactly: 11/24/2019T10:41:29
--version                      now gives date and time of build in additon to 7.16.33
```
Filtering of project messages is done in the debug section of cc_config.xml and allows for
hiding messages that obscure the limited amount of space visible in the event log.  In addition, 
some non-project messages such as "Backing off" are displayed only when the project name changes.
```
<exclude_proj_msg>       <! put this in the flags section, not the options section -->
<proj_name></proj_name>  <!-- project name with correct syntax are isted in event messages -->
<msg_type>low</msg_type>
<msg_content></msg_content>  <!-- if enmpty, all are excluded -->
</exclude_proj_msg>
```
Some useful filters
```
<msg_content>settings do not allow fetching tasks</msg_content>
<msg_content>No work available</msg_content>
<msg_content>No work sent</msg_content>
<msg_content>No work is available</msg_content>
```
Additional debug switches
```
<debug_proj_msg>0</debug_proj_msg>
<mw_debug>0</mw_debug>
```
New option parameters (in options section)
```
<spoof_gpus>16</spoof_gpus>
<allow_all_msgs>0</allow_all_msgs>
<busid_info_file>/etc/boinc-client/cc_include.xml</busid_info_file>
<mw_bug_fix>0</mw_buf_fix>  <!-- enable milkyway bug fix -->
```                     
New app_config.xml parameter for projects:  spoofed value here overrides any global spoof value
```
<app_config>
 <spoofedgpus>4</spoofedgpus>
</app_config>
```

This project is named master - slave as the intent is to use the project information at \ProjectData\Boinc
(or /var/lib/boinc) as a master and make copies of it using an incrementing hostname, same password, and
incrementing RPC port to create and run multiple clients. This is useful if a project goes offline and
spoofing the number of GPUs does not provide an adaquate number of work units to continue crunching during
the outage. The scripts, bash and cmd, to perform this function are under construction.

The Milkyway bug fix is automatically enabled if the debug flag <mw_debug>1<mw_debug> exists
Bus ID and BOINC ID can be correlated to the coprocessor board for better identificiation but this
requires running the [MakeTable.py](https://github.com/JStateson/BoincTasks) script.  Once run, the correlation can show something like the following
```
Manu  Boinc  Manu   BusID     Board
 ID    ID    Name   (hex)     Name
  0     5    NV   01:00.0    GTX-1070	
  1     0    NV   02:00.0    GTX-1660-Ti	
  2     1    NV   03:00.0    P102-100	
  3     2    NV   04:00.0    P102-100	
  4     3    NV   05:00.0    P102-100	
  5     4    NV   06:00.0    GTX-1070-Ti
  ```
