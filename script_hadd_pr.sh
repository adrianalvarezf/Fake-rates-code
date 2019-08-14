
pwd


cd $1"/outputs"$1
pwd

rm -r PR_mu.root
rm -r PR_ele.root

hadd -f -k PR_mu.root *mu*DY*.root
hadd -f -k PR_ele.root *ele*DY*.root

cd -

