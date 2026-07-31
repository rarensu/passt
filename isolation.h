/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright Red Hat
 * Author: Stefano Brivio <sbrivio@redhat.com>
 * Author: David Gibson <david@gibson.dropbear.id.au>
 */

#ifndef ISOLATION_H
#define ISOLATION_H

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

struct ctx;

struct inherited_fds {
	int *fds;
	size_t count;
};

void isolate_initial(void);
void collect_inherited_fds(struct inherited_fds *list);
void cleanup_inherited_fds(struct inherited_fds *list, int keep_fd);
void isolate_user(const struct ctx *c, uid_t uid, gid_t gid, bool use_userns,
		  const char *userns);
int isolate_prefork(const struct ctx *c);
void isolate_postfork(const struct ctx *c);

#endif /* ISOLATION_H */
