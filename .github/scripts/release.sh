#!/bin/bash

VERSION=$(awk '/VERSION/ { gsub("\"", "", $3); print $3 }' cst.h)
TAR_NAME=cst_${VERSION}.tar.gz
tar -czvf $TAR_NAME cst.*
sha256sum $TAR_NAME > sha256sum.txt
git tag v${VERSION}
git push origin v${VERSION}

