
# Remove the previous results file

rm -f slist-int-reverse-v2-eval.txt

# Run the evaluation

for i in {2000,4000,6000,8000,10000}; do
  ./slist-int-reverse-v2-eval $i | tee -a slist-int-reverse-v2-eval.txt;
done

