df <- read.csv("heart.csv")

# 1 CI
disease <- df[df$target==1, "age"]
n <- length(disease)
mean <- mean(disease)
sd <- sd(disease)
tcrit <- qt(0.975, df=n-1)
ci <- c(mean - tcrit*sd/sqrt(n), mean + tcrit*sd/sqrt(n))
print(ci)

# 2 Levene + t-test
library(car)
print(leveneTest(chol ~ factor(target), data=df))
print(t.test(chol ~ target, data=df, var.equal=FALSE))

# 3 ANOVA
df$age_group <- cut(df$age, breaks=c(0,40,55,200), labels=c("<40","40-55",">55"))
anova_result <- aov(thalach ~ age_group, data=df)
print(summary(anova_result))