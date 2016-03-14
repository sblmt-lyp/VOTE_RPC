/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "vote-sys.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
vote_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		voter_pack changepassword_1_arg;
		voter_pack addvoter_1_arg;
		voter_pack votefor_1_arg;
		voter_pack votecount_1_arg;
		voter_pack viewresult_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case changepassword:
		_xdr_argument = (xdrproc_t) xdr_voter_pack;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) changepassword_1_svc;
		break;

	case zeroize:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) zeroize_1_svc;
		break;

	case addvoter:
		_xdr_argument = (xdrproc_t) xdr_voter_pack;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) addvoter_1_svc;
		break;

	case votefor:
		_xdr_argument = (xdrproc_t) xdr_voter_pack;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) votefor_1_svc;
		break;

	case listcandidates:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) listcandidates_1_svc;
		break;

	case votecount:
		_xdr_argument = (xdrproc_t) xdr_voter_pack;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) votecount_1_svc;
		break;

	case viewresult:
		_xdr_argument = (xdrproc_t) xdr_voter_pack;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) viewresult_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (VOTE_PROG, VOTE_VER);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, VOTE_PROG, VOTE_VER, vote_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (VOTE_PROG, VOTE_VER, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, VOTE_PROG, VOTE_VER, vote_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (VOTE_PROG, VOTE_VER, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
