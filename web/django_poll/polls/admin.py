from django.contrib import admin
from polls.models import Question, Choice

class ChoiceInline(admin.StackedInline):
    model = Choice
    extra = 3

class QuestionAdmin(admin.ModelAdmin):
    #fields = ['pub_date', 'question_text']
    fieldsets = [
            (None, {'fields': ['question_text']}),
            ('Date Information', {'fields': ['pub_date'], 'classes': ['collapse']}),
            ]
    inlines = [ChoiceInline]

admin.site.register(Question, QuestionAdmin)

