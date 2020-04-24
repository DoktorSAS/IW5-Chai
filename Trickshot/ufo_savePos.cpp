/* 
# Develped by DoktorSAS
# MOD: Save Position on change team + UFO Mode using spectator team
# Description: This is a simple script using chai to load position with switching team
#			   from spectator to something else. 
*/

global position = Vector();
global angles = Vector();
global savedpos = Vector();
global onSpect = Vector();
for(var i = 0; i < 18 ; ++i){
position.push_back([0,0,0]);
angles.push_back([0,0,0]);
savedpos.push_back(0);
onSpect.push_back(0);
}
level.onNotify("connected", onPlayerConnected);

def onPlayerConnected(args){
	var player = args[0];
	var pNum = player.getEntityNumber();
	player.AllowSpectateTeam("freelook", true); //Allow fly on spectator team
	player.onNotify("menuresponse", fun[player, pNum](args) { //Made by DoktorSAS
            if(arguments[0] == "changeclass"){ //Menu response on changeclass
                //arguments[1] = class selected
            }else if(arguments[0] == "team_marinesopfor"){ //Menu response on team change
                if(arguments[1] == "axis" || arguments[1] == "axis" && onSpect[pNum] == 1 && playerscore[pNum] == 200){
					position[pNum] = player.getOrigin();
					angles[pNum] = player.getPlayerAngles();
					savedpos[pNum] = 1;
					player.iPrintln("Position ^2Saved");
					onSpect[pNum] = 0;
				}else{
					onSpect[pNum] = 1;
					player.iPrintlnBold("Joined in ^5UFO ^7Mode");
				}
            }
    });
}

