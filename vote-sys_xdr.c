/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "vote-sys.h"

bool_t
xdr_voter_pack (XDR *xdrs, voter_pack *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_char (xdrs, &objp->command))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->password, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->username, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->new_password, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->cname, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->voter_id))
		 return FALSE;
	return TRUE;
}
