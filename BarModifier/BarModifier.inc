[Variables]
VPN_Status-Mike_Boynton.LeftMouseDownAction=[]
VPN_Status-Mike_Boynton.MouseOverAction=[]
VPN_Status-Mike_Boynton.MouseLeaveAction=[]
VPN_Status-Mike_Boynton.ButtonAction=[]

[VPN_Status-Mike_Boynton.Style]
W=((((#TopHeight#+#TopBarIconHOffset#)*1.5))-((((#TopHeight#+#TopBarIconHOffset#)*1.5)%1)))
ImageAlpha=0

[VPN_Status-Mike_Boynton]
Meter=Image
MeterStyle=InfoStyle | CustomAppModifierStyle
ImageName=#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Button\Medium\Button[#TopIconShadows100]-#VPNOnOff#.png
H=(#TopHeight#+#TopBarIconHOffset#)
Padding=#SysIconPadding#
MouseOverAction=[]
MouseLeaveAction=[]
Group=CustomApp[##CURRENTSECTION#]Sys | SysTray | Buttons00 | AppButton[##CURRENTSECTION#] | CustomAppButton | CustomAppColor[##CURRENTSECTION#]