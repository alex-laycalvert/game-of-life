# Maintainer: Alex Lay-Calvert <alex.laycalvert@gmail.com>
pkgname=gol
pkgver=1.0.0
pkgrel=1
pkgdesc="An implementation of John Conway's Game of Life"
arch=(x86_64)
url="github.com/alex-laycalvert/gol.git"
license=('MIT')
groups=()
depends=('ncurses')
makedepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=(git+https://$url)
noextract=()
md5sums=("SKIP")
build() {
    cd "$pkgname"
    make
}
package() {
    cd "$pkgname"
    make DESTDIR="$pkgdir/" install
}
