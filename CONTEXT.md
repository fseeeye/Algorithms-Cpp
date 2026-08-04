# Algorithm Practice Repository

This repository organizes algorithm practice material into independently usable units while retaining topic- and source-based navigation.

## Language

**Exercise**:
The repository's smallest self-contained practice unit: one problem or reusable implementation together with the material needed to understand and verify it.
_Avoid_: Question, problem target, category executable

**Problem Exercise**:
An Exercise based on an externally specified problem, retaining that problem's identity and native public interface.
_Avoid_: Template Exercise, generic template

**Template Exercise**:
A reusable algorithm, data structure, or reference implementation developed without an external problem identity. The term covers both general practice templates and C++ template-based implementations.
_Avoid_: Problem Exercise, judge problem

**Review Exercise**:
An Exercise retained for revisiting previously encountered material. It follows the same independent verification model as other Exercises but is not published in the Exercise Index.
_Avoid_: Legacy executable, indexed Exercise, untested review snippet

**Exercise ID**:
The globally unique, stable identity of an Exercise. A Problem Exercise derives it from its problem series and external identifier; a Template Exercise derives it from its practice domain and subject.
_Avoid_: Display name, topic path, solution class name

**Exercise Domain**:
The Exercise's top-level repository context—Algorithm, DataStructure, or Review—determined by where the Exercise lives. It is distinct from a narrower knowledge category such as binary search or tree.
_Avoid_: User-supplied domain, topic category, problem source

**Exercise Test**:
The sole verification form for an Exercise: a repeatable set of behavioral assertions that invokes the Exercise through its public interface and passes when the Exercise is considered complete.
A newly generated scaffold is intentionally incomplete and contains a fail-fast sentinel until its commented API example is replaced by real assertions.
_Avoid_: Runner, demo, interactive verification, source-specific test, compile-only check, passing or permanent placeholder test

**Native Exercise Interface**:
The public API shaped by the Exercise itself, preserving an external problem's contract or exposing the natural operations of a reusable implementation. The repository does not impose a universal input/output wrapper on Exercises.
_Avoid_: Repository-wide `solve(Input) -> Output`, mandatory stream adapter, test-only public API

**Exercise Support Library**:
Shared types and utilities that reproduce or supplement the environment assumed by Exercises, such as judge-provided list and tree node types. It is supporting material, not an Exercise or a practiced data-structure implementation.
_Avoid_: Exercise, core data structures, data-structure solution

**Exercise Metadata**:
The canonical structured description of an Exercise used for cataloging it, including its identity and human-facing classification. Generated views derive their contents from this description.
_Avoid_: README row, build target definition, duplicated catalog data

**Exercise Reference**:
An optional external URL identifying source material for an Exercise, such as an original problem statement or a reference for a reusable implementation. It is distinct from the repository-local link used to navigate to the Exercise.
_Avoid_: Exercise path, README navigation link, Problem-only URL

**Exercise Index**:
A generated, human-readable navigation view of the repository's algorithm and data-structure Exercises, organized by the repository's knowledge categories and derived from Exercise Metadata. Review Exercises are intentionally excluded.
_Avoid_: Manually maintained solution list, metadata source
