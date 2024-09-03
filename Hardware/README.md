<div align="center">
  
[![PCBWay](https://github.com/user-attachments/assets/d836a4a7-516c-4f2f-8547-6fc7cfca758b)](www.pcbway.com)
###### Partnering with PCBway.
</div>
<br/>


# Hardware
## General Information 

Warning: This project uses lasers. Be sure to **always** do your own testing by meassuring voltage and current and by looking in datasheets. I am **not** responsible for any injuries you encounter from using this project. Also make sure to wear proper eye-protection.




-----

**The Grenade runs using 3 1,2V NiMh batteries! Don't use voltages greater than 5V in order to power it.**

----

  **We recommend not to use a laser diode for the grenade, since it can be dangerous. Use a normal IR LED instead.** 

## The code

To flash the program to your ESP8266 you need to have <a href="https://code.visualstudio.com/">Visual Studio Code</a> and the platformio extension installed. If you haven't you can follow this tutorial:
<a>https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/</a> To flash an ESP8266 from Windows you might need additional drivers, you'll find a tutorial on this here https://randomnerdtutorials.com/install-esp32-esp8266-usb-drivers-cp210x-windows/


## Building the Grenade

#### Perf matrix board
If you're using a perf matrix board, make sure to cut out a 6x6 cm square.

#### PCB
We created the pcb layout with <a href="https://www.kicad.org/">KiCad</a>. You can easily order really nice high-quality PCBs from our partner [PCBWay](www.pcbway.com) by using the PCBWay plugin in KiCAD following this [turorial](https://www.pcbway.com/blog/News/PCBWay_Plug_In_for_KiCad_3ea6219c.html), exporting the gerber files manually like explained [here](https://www.pcbway.com/blog/help_center/How_to_Generate_Gerber_and_Drill_Files_in_KiCad_7_0_ab0d12bb.html) or use the gerber files in the repository (possibly outdated or not-yet available).


<img src="https://github.com/user-attachments/assets/2d0a36ec-5314-4bf2-8cd0-de0de4358181" width=300/> <img src="https://github.com/user-attachments/assets/41335f11-8d60-466a-965a-b0f244fbd1c7" width=300 />

----

1. Make sure you have got all the required parts
2. Solder pins to your ESP d1 mini
3. Flash the ESP
5. Solder the components to your perf board ore PBC
6. Solder cables to your button
7. Drill a small hole in the grenade shell and glue in the button
8. Solder a switch in the red cable of the battery clip
9. Crimp sockets on your battery clip 
12. Crimp sockets to the cables of the LED strip
13. Crimp sockets to the cables of the button
14. Connect LED strip, button and power
15. Glue the PCB or matrix board in the shell
    ![image](https://github.com/user-attachments/assets/8df8b442-4ac6-49e9-aa09-634c269f5c46)

17. Cut 4 pieces of 6mm x 30mm metal rod or tube
18. Heat up the pieces with a lighter and press them half way into the holes in one half of the shell until
   ![image](https://github.com/user-attachments/assets/f50a0486-8a80-4a2c-aa5f-977053b177d6)

20. Close the shell
21. Screw on the battery cover
22. Cuddle your cat
    
