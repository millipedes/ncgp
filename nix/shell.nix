with import <nixpkgs> {}; {
  projectEnv = stdenv.mkDerivation {
    name = "ncurses";
    buildInputs = [stdenv libpng];
    propagateBuildInputes = [ncurses];
  };
}

