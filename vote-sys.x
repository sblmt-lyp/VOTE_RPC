
struct voter_pack{
	char command;
	char password[100];
	char username[100];
	char new_password[100]; 
	char cname[100];
	int voter_id;
};



program VOTE_PROG{
	version VOTE_VER{

	string changepassword(voter_pack) = 1;
	string zeroize(void) = 2;
	string addvoter(voter_pack) = 3;
	string votefor(voter_pack) = 4;
	string listcandidates(void) = 5;
	string votecount(voter_pack) = 6;
	string viewresult(voter_pack) = 7;
	} = 1;

} = 0x29356488;