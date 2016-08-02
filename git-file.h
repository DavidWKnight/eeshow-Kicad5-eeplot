/*
 * git-file.h - Open and read a file from git version control system
 *
 * Written 2016 by Werner Almesberger
 * Copyright 2016 by Werner Almesberger
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef GIT_FILE_H
#define	GIT_FILE_H

#include <stdbool.h>


/*
 * future-proofing: if someone wants to add back-ends for other version control
 * systems, the identifiers will already be there.
 */

#define	vcs_open	vcs_git_open
#define	vcs_read	vcs_git_read
#define	vcs_close	vcs_git_close


struct vcs_git;
struct file;

struct vcs_git *vcs_git_open(const char *revision, const char *name,
    const struct vcs_git *related);
void vcs_git_read(void *ctx, struct file *file,
    bool (*parse)(const struct file *file, void *user, const char *line),
    void *user);
void vcs_git_close(void *ctx);

#endif /* !GIT_FILE_H */
