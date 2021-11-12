
# Remove the previous results file

rm -f slist-dpoly-reverse-v1-eval.txt

# Run the evaluation

for i in {200,400,600,800,1000}; do
  ./slist-dpoly-reverse-v1-eval $i | tee -a slist-dpoly-reverse-v1-eval.txt;
done

