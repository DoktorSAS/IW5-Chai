/* 
# Develped by DoktorSAS
# MOD: Sucide when shoot on ground
# Description: This is a simple script using chai to sucide shooting on
#			   ground, not the nest solution but is a solution.
*/

level.onNotify("connected", onPlayerConnected);
def onPlayerConnected(args){
	var player = args[0];
	var pNum = player.getEntityNumber();
	player.onNotify("weapon_fired", fun[player, pNum](args) {
		if(player.getPlayerAngles[0] == 85){
			player.suicide();
		}
	});
}

