[Rainmeter]

[Variables]

;----------------------------------------------------
; # # ADD BACKGROUND PROCESSES BELOW # # # # # # # #
; # # Measures that run even when the app isn't open
;----------------------------------------------------

;----------------------------------------------------------------------
; Example # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
; Updates the top bar when CPU temperature changes
; 
; UpdateDivider=10 rechecks the temperature every 10 seconds
; Recommended this number be no lower than 10 to prevent high CPU usage
;----------------------------------------------------------------------

[MeasureNetwork]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=BEST
RegExpSubstitute=1
Substitute="^(.*)\.(.*)\.(.*)\.(.*)$":"\1"
DynamicVariables=1
OnChangeAction=[!UpdateMeasure *][!CommandMeasure MeasureVPNWANIP "Update"]

;[VPNStatus]
;Measure=Calc
;Formula=[MeasureNetwork]
;IfBelowValue=192
;IfBelowAction=[!SetVariable VPNOnOff "1" "Droptop\DropdownBar"][!WriteKeyValue Variables FColor "0,255,0,255" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOffText "ON" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOff "1" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!SetOption 1Status FontColor "0,255,0,255" "Droptop Community Apps\Apps\#MyAppID#"][!SetOption 1Status Text "ON" "Droptop Community Apps\Apps\#MyAppID#"][!UpdateMeter 1Status "Droptop Community Apps\Apps\#MyAppID#"][!Redraw "Droptop Community Apps\Apps\#MyAppID#"]
;IfAboveValue=191
;IfAboveAction=[!SetVariable VPNOnOff "0" "Droptop\DropdownBar"][!WriteKeyValue Variables FColor "255,0,0,255" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOffText "OFF" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOff "0" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!SetOption 1Status FontColor 255,0,0,255 "Droptop Community Apps\Apps\#MyAppID#"][!SetOption 1Status Text "OFF" "Droptop Community Apps\Apps\#MyAppID#"][!UpdateMeter 1Status "Droptop Community Apps\Apps\#MyAppID#"][!Redraw "Droptop Community Apps\Apps\#MyAppID#"]
;DynamicVariables=1
;UpdateDivider=-1
;OnChangeAction=[!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!Redraw]

[VPNStatus]
Measure=SysInfo
SysInfoType=ADAPTER_ALIAS
SysInfoData=Best
DynamicVariables=1
IfMatch=Wi-Fi|Ethernet
IfMatchAction=[!SetVariable VPNOnOff "0" "Droptop\DropdownBar"][!WriteKeyValue Variables FColor "255,0,0,255" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOffText "OFF" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOff "0" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!SetOption 1Status FontColor 255,0,0,255 "Droptop Community Apps\Apps\#MyAppID#"][!SetOption 1Status Text "OFF" "Droptop Community Apps\Apps\#MyAppID#"][!UpdateMeter 1Status "Droptop Community Apps\Apps\#MyAppID#"][!Redraw "Droptop Community Apps\Apps\#MyAppID#"]
IfNotMatchAction=[!SetVariable VPNOnOff "1" "Droptop\DropdownBar"][!WriteKeyValue Variables FColor "0,255,0,255" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOffText "ON" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOff "1" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!SetOption 1Status FontColor "0,255,0,255" "Droptop Community Apps\Apps\#MyAppID#"][!SetOption 1Status Text "ON" "Droptop Community Apps\Apps\#MyAppID#"][!UpdateMeter 1Status "Droptop Community Apps\Apps\#MyAppID#"][!Redraw "Droptop Community Apps\Apps\#MyAppID#"]
OnChangeAction=[!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!Redraw]

[MeasureVPNWANIP]
Measure=WebParser
URL=https://ipwho.is/
RegExp=(?siU)"ip":"(.*)".*"country":"(.*)".*"region":"(.*)".*"city":"(.*)".*"latitude":(.*),".*longitude":(.*),"
UpdateRate=3600
Substitute=#VPNSubstitute#
StringIndex=1
FinishAction=[!SetVariable VPNWANIP "[MeasureVPNWANIP]"][!SetVariable VPNCountry "[MeasureVPNCountry]"][!SetVariable VPNRegion "[MeasureVPNRegion]"][!SetVariable VPNCity "[MeasureVPNCity]"][!SetVariable VPNLat "[MeasureVPNLat]"][!SetVariable VPNLong "[MeasureVPNLong]"][!SetVariable VPNWANIP "[MeasureVPNWANIP]" "Droptop Community Apps\Apps\#MyAppID#"][!SetVariable VPNCountry "[#VPNCountry]" "Droptop Community Apps\Apps\#MyAppID#"][!SetVariable VPNRegion "[#VPNRegion]" "Droptop Community Apps\Apps\#MyAppID#"][!SetVariable VPNCity "[MeasureVPNCity]" "Droptop Community Apps\Apps\#MyAppID#"][!SetVariable VPNLat "[MeasureVPNLat]" "Droptop Community Apps\Apps\#MyAppID#"][!SetVariable VPNLong "[MeasureVPNLong]" "Droptop Community Apps\Apps\#MyAppID#"][!WriteKeyValue Variables VPNWANIP "[MeasureVPNWANIP]" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNCountry "[MeasureVPNCountry]" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNRegion "[MeasureVPNRegion]" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNCity "[MeasureVPNCity]" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNLat "[MeasureVPNLat]" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNLong "[MeasureVPNLong]" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeter * "Droptop Community Apps\Apps\#MyAppID#"][!Redraw "Droptop Community Apps\Apps\#MyAppID#"][!CommandMeasure VPNCheck "Update"]

[MeasureVPNCountry]
Measure=WebParser
URL=[MeasureVPNWANIP]
UpdateRate=3600
Substitute=#VPNSubstitute#
StringIndex=2

[MeasureVPNRegion]
Measure=WebParser
URL=[MeasureVPNWANIP]
UpdateRate=3600
Substitute=#VPNSubstitute#
RegExpSubstitute=1
StringIndex=3

[MeasureVPNCity]
Measure=WebParser
URL=[MeasureVPNWANIP]
UpdateRate=3600
Substitute=#VPNSubstitute#
StringIndex=4

[MeasureVPNLat]
Measure=WebParser
URL=[MeasureVPNWANIP]
UpdateRate=3600
RegExpSubstitute=1
Substitute=#VPNSubstitute#
StringIndex=5

[MeasureVPNLong]
Measure=WebParser
URL=[MeasureVPNWANIP]
UpdateRate=3600
Substitute=#VPNSubstitute#
StringIndex=6

;[VPNCheck]
;Measure=WebParser
;URL=https://check.getipintel.net/check.php?ip=#VPNWANIP#&contact=mkboynton@ymail.com&format=json&flags=b
;RegExp=(?siU)"result":"(.*)".*
;UpdateRate=3600
;StringIndex=1
;DynamicVariables=1
;FinishAction=[!UpdateMeasure "VPNCheckCalc"][!CommandMeasure VPNCheckCalc "Update"]

;[VPNCheckCalc]
;Measure=Calc
;Formula=[VPNCheck]
;IfEqualValue=0
;IfEqualAction=[!SetVariable VPNOnOff "0" "Droptop\DropdownBar"][!WriteKeyValue Variables FColor "255,0,0,255" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOffText "OFF" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOff "0" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!SetOption 1Status FontColor 255,0,0,255 "Droptop Community Apps\Apps\#MyAppID#"][!SetOption 1Status Text "OFF" "Droptop Community Apps\Apps\#MyAppID#"][!UpdateMeter 1Status "Droptop Community Apps\Apps\#MyAppID#"][!Redraw "Droptop Community Apps\Apps\#MyAppID#"]
;IfEqualValue2=1
;IfEqualAction2=[!SetVariable VPNOnOff "1" "Droptop\DropdownBar"][!WriteKeyValue Variables FColor "0,255,0,255" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOffText "ON" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!WriteKeyValue Variables VPNOnOff "1" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!SetOption 1Status FontColor "0,255,0,255" "Droptop Community Apps\Apps\#MyAppID#"][!SetOption 1Status Text "ON" "Droptop Community Apps\Apps\#MyAppID#"][!UpdateMeter 1Status "Droptop Community Apps\Apps\#MyAppID#"][!Redraw "Droptop Community Apps\Apps\#MyAppID#"]
;DynamicVariables=1
;UpdateDivider=-1
;OnChangeAction=[!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!Redraw]